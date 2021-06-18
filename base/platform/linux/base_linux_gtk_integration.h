/*
This file is part of Telegram Desktop,
the official desktop application for the Telegram messaging service.

For license and copyright information please follow this link:
https://github.com/telegramdesktop/tdesktop/blob/master/LEGAL
*/
#pragma once

#include "base/const_string.h"

#include <QtCore/QLibrary>

namespace base {
namespace Platform {

class GtkIntegration {
public:
	static GtkIntegration *Instance();

	QLibrary &library() {
		return _lib;
	}

	void load();
	[[nodiscard]] bool loaded() const;

	[[nodiscard]] bool checkVersion(
		uint major,
		uint minor,
		uint micro) const;

	[[nodiscard]] std::optional<bool> getBoolSetting(
		const QString &propertyName) const;

	[[nodiscard]] std::optional<int> getIntSetting(
		const QString &propertyName) const;

	[[nodiscard]] std::optional<QString> getStringSetting(
		const QString &propertyName) const;

	void connectToSetting(
		const QString &propertyName,
		void (*callback)());

private:
	GtkIntegration();
	QLibrary _lib;
};

} // namespace Platform
} // namespace base
