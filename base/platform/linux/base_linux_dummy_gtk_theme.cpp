// This file is part of Desktop App Toolkit,
// a set of libraries for developing nice desktop applications.
//
// For license and copyright information please follow this link:
// https://github.com/desktop-app/legal/blob/master/LEGAL
//
#include "base/const_string.h"

#include <qpa/qplatformthemeplugin.h>
#include <private/qgenericunixthemes_p.h>

#include <range/v3/all.hpp>

namespace base::Platform {
namespace {

constexpr auto kNames = {
	"gtk3"_cs,
	"gtk2"_cs,
	"qt5gtk2"_cs,
	"gnome"_cs,
	"qgnomeplatform"_cs,
};

} // namespace

class DesktopAppDummyGtkThemePlugin : public QPlatformThemePlugin {
	Q_OBJECT
	Q_PLUGIN_METADATA(IID QPlatformThemeFactoryInterface_iid FILE "base_linux_dummy_gtk_theme.json")

public:
	QPlatformTheme *create(const QString &key, const QStringList &params) override {
		const auto chosen = ranges::any_of(kNames, [&](const auto &name) {
			return !key.compare(name.utf16(), Qt::CaseInsensitive);
		});

		if (chosen) {
			return new QGnomeTheme;
		}

		return nullptr;
	}
};

} // namespace base::Platform

#include "base_linux_dummy_gtk_theme.moc"
