// This file is part of Desktop App Toolkit,
// a set of libraries for developing nice desktop applications.
//
// For license and copyright information please follow this link:
// https://github.com/desktop-app/legal/blob/master/LEGAL
//
#include <QtWidgets/QStylePlugin>

namespace base::Platform {

class DesktopAppDummyGtkStylePlugin : public QStylePlugin {
	Q_OBJECT
	Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QStyleFactoryInterface" FILE "base_linux_dummy_gtk_style.json")

public:
	QStyle *create(const QString &key) {
		return nullptr;
	}
};

} // namespace base::Platform

#include "base_linux_dummy_gtk_style.moc"
