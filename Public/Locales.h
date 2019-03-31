////////////////////////////////////////////////////////////////
//
// SURVIVALHOST
// Locale system
// 
////////////////////////////////

#pragma once

// locale types
#define STR_T std::wstring
#define STR() Strings::Get()
#define STR_F(s, ...) fmt::format(Strings::Get()->s, __VA_ARGS__)
#define STR_P(player, s) Strings::Get(player)->s
#define STR_P_F(player, s, ...) fmt::format(Strings::Get(player)->s, __VA_ARGS__)

// plugin types
#include "Plugin.h"

// exports
#define SURVIVALHOST_API __declspec(dllimport)

// locale storage
namespace SHLocale
{
	// get plugin-defined strings
	SURVIVALHOST_API std::string Get();

	// get player-defined strings (defaults to plugin-defined)
	SURVIVALHOST_API std::string Get(unsigned long long steam_id);

	// set player-defined strings (usign steam_id, defaults to plugin-defined)
	SURVIVALHOST_API void Set(const unsigned long long steam_id, std::string locale);

	// Init    
	// init database
	void Init(void);

	// Unload
	// unload database
	void Unload(void);
}