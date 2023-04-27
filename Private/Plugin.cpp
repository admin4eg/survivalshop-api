////////////////////////////////////////////////////////////////
//
// SURVIVALSHOP API
// Plugin to add "permission" item to custom goods definitions
// (c) Pavel [VorteX] Timofeev
//
////////////////////////////////

#include "Plugin.h"
#include "ShopApi.h"
#include "Permissions.h"
#include "Utils.h"

#ifdef COMMON_ATLAS
#pragma comment(lib, "AtlasApi.lib")
#else
#pragma comment(lib, "ArkApi.lib")
#endif

#pragma comment(lib, "cpprest141_2_10.lib")
#pragma comment(lib, "SurvivalHost.lib")
#pragma comment(lib, "SurvivalShop.lib")
#pragma comment(lib, "Permissions.lib")

namespace Plugin
{
	std::string Name = "SurvivalShopPermissions";
	std::string Version = "1.1";
	std::string VersionState = "";
	std::string Credits = "SurvivalShop.org";
}

// apply permissions
bool PermissionsEquip(const unsigned long long steamId, const web::json::value *customItem, std::wstring *logMessage)
{
	bool success = true;

	std::wstring a = Utils::ToLower(customItem->at(L"do").as_string());

	std::wstring group = customItem->at(L"group").as_string();
	FString fgroup(group);

	if (group == L"")
	{
		// forgot to set group
		*logMessage = STR_F(ErrorChangingPermissions___0, L"1");
		success = false;
	}
	else if (a == L"add")
	{
		// add to group
		*logMessage = STR_F(AddPermissions_0, group);
		Permissions::AddPlayerToGroup(steamId, fgroup);

		// set timer
		int minutes = -1;
		if (customItem->has_field(L"minutes") || customItem->has_field(L"hours") || customItem->has_field(L"days"))
		{
			minutes = 0;
			if (customItem->has_field(L"minutes"))
				minutes = minutes + customItem->at(L"minutes").as_integer();
			if (customItem->has_field(L"hours"))
				minutes = minutes + customItem->at(L"hours").as_integer() * 60;
			if (customItem->has_field(L"days"))
				minutes = minutes + customItem->at(L"days").as_integer() * 60 * 24;
		}

		// add to print string
		if (minutes > 0)
			*logMessage += L" (" + Utils::MinutesToTimeString(minutes, STR_P(steamId, Years), STR_P(steamId, Days), STR_P(steamId, Hours), STR_P(steamId, Minutes)) + L")";

		// end timer message
		std::wstring endMessage = L"";
		if (minutes > 0)
		{
			if (customItem->has_field(L"endMessage"))
				endMessage = customItem->at(L"endMessage").as_string();
			else
				endMessage = STR_P_F(steamId, Permission_0_HasBeenEnded, group);
		}

		SurvivalShopApi::SetTimer(L"permissions", steamId, group, endMessage, L"", minutes);

		success = true;
	}
	else if (a == L"remove")
	{
		// remove from group
		*logMessage = STR_F(RemovePermissions_0, group);
		Permissions::RemovePlayerFromGroup(steamId, fgroup);
		success = true;
	}
	else
	{
		// forgot to set "do"
		*logMessage = STR_F(ErrorChangingPermissions___0, L"2");
		success = false;
	}
	return success;
}

// end permissions
void PermissionsTimer(const unsigned long long id, unsigned long long steamId, const std::wstring *data, const std::wstring *auxData, const std::wstring *comment, std::wstring *playerMessage)
{
	// remove from group
	FString group(*data);
	Permissions::RemovePlayerFromGroup(steamId, group);

	// set player message
	*playerMessage = *auxData;
}

// Load()
// load plugin
void Load(void)
{
	if (SurvivalShopApi::Version() < 1.1)
		return;

	// register
	SurvivalShopApi::RegisterEquipmentType(L"SurvivalShopPermissions", L"permissions", &PermissionsEquip);
	SurvivalShopApi::RegisterTimerType(L"SurvivalShopPermissions", L"permissions", &PermissionsTimer);
}

// Unload
// unload plugin
void Unload(void)
{
	if (SurvivalShopApi::Version() < 1.1)
		return;

	// unregister equipment
	SurvivalShopApi::UnregisterEquipmentType(L"permissions");
	SurvivalShopApi::UnregisterTimerType(L"permissions");
}

// DLL main
BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		Load();
		break;
	case DLL_PROCESS_DETACH:
		Unload();
		break;
	}
	return TRUE;
}
