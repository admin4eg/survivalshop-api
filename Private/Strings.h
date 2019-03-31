////////////////////////////////////////////////////////////////
//
// SURVIVALHOST
// Default locale strings
// 
////////////////////////////////

#pragma once

#include "Locales.h"

namespace Strings
{
	class Strings {
	public:
		STR_T ErrorChangingPermissions___0 = L"Error changing permissions: {0}";
		STR_T AddPermissions_0 = L"add permissions {0}";
		STR_T RemovePermissions_0 = L"remove permissions {0}";
	};

	// get player-defined strings for locale
	// defined in plugin:
	Strings *Get(std::string locale);

	// Get strings from locale
	Strings *Get();

	// get player-defined strings (defaults to plugin-defined)
	Strings *Get(unsigned long long steam_id);

	// get player-defined strings (defaults to plugin-defined)
	Strings *Get(AShooterPlayerController *player);
	Strings *Get(APlayerController *player);

	// set player-defined strings (usign AShooterPlayerController *, defaults to plugin-defined)
	void Set(AShooterPlayerController *player, std::string locale);
	void Set(APlayerController *player, std::string locale);
}