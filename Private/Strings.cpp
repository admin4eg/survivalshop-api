////////////////////////////////////////////////////////////////
//
// SURVIVALHOST
// Managed locale strings
// 
////////////////////////////////

#include "Plugin.h"

#include "Strings.h"

// EN  EN  EN  EN  EN  EN  EN  EN  EN  EN  EN  EN  EN  EN  EN  EN  EN  EN  EN  EN  EN  EN  EN  EN  EN  EN  EN  EN  EN  EN
class En : public Strings::Strings { public: En() { } };

// RU  RU  RU  RU  RU  RU  RU  RU  RU  RU  RU  RU  RU  RU  RU  RU  RU  RU  RU  RU  RU  RU  RU  RU  RU  RU  RU  RU  RU  RU
class Ru : public En {
public: Ru() : En() {
	this->ErrorChangingPermissions___0 = L"ѕроблемы изменени€ прав: {0}";
	this->AddPermissions_0 = L"выдача прав {0}";
	this->RemovePermissions_0 = L"сн€тие прав {0}";
	this->Permission_0_HasBeenEnded = L"врем€ {0} закончилось";
	this->Unlimited = L"бессрочно";
	this->Minutes = L"минут";
	this->Hours = L"часов";
	this->Days = L"дней";
	this->Years = L"лет";
}
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// GET LOCALE
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace Strings
{
	static Ru RuStrings;
	static En EnStrings;

	// Get strings fro locale
	Strings *Get(std::string locale)
	{
		if (locale == "ru")
			return (Strings*)&RuStrings;
		return (Strings*)&EnStrings;
	}

	// Get strings fro locale
	Strings *Get()
	{
		return Get(SHLocale::Get());
	}

	// get player-defined strings (defaults to plugin-defined)
	Strings *Get(unsigned long long steam_id)
	{
		return Get(SHLocale::Get(steam_id));
	}

	// get player-defined strings (defaults to plugin-defined)
	Strings *Get(AShooterPlayerController *player)
	{
		return Get(ArkApi::IApiUtils::GetSteamIdFromController(player));
	}
	Strings *Get(APlayerController *player)
	{
		return Get(static_cast<AShooterPlayerController*>(player));
	}

	// set player-defined strings (usign AShooterPlayerController *, defaults to plugin-defined)
	void Set(AShooterPlayerController *player, std::string locale)
	{
		const unsigned long long steam_id = ArkApi::IApiUtils::GetSteamIdFromController(player);
		if (steam_id == 0)
			return;
		SHLocale::Set(steam_id, locale);
	}
	void Set(APlayerController *player, std::string locale)
	{
		Set(static_cast<AShooterPlayerController*>(player), locale);
	}
}