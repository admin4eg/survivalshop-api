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

#pragma comment(lib, "ArkApi.lib")
#pragma comment(lib, "SurvivalHost.lib")
#pragma comment(lib, "SurvivalShop.lib")
#pragma comment(lib, "Permissions.lib")

bool PermissionsEquip(const unsigned long long steamId, const web::json::value *customItem, std::wstring *logMessage)
{
	bool success = true;

	std::wstring a = Utils::ToLower(customItem->at(L"do").as_string());

	std::wstring group = customItem->at(L"group").as_string();
	FString fgroup(group);

	if (group == L"")
	{
		// забыли указать группу в конфиг-файле
		*logMessage = STR_F(ErrorChangingPermissions___0, L"1");
		success = false;
	}
	else if (a == L"add")
	{
		// добавление группы
		*logMessage = STR_F(AddPermissions_0, group);
		Permissions::AddPlayerToGroup(steamId, fgroup);
		success = true;
	}
	else if (a == L"remove")
	{
		// удаление группы
		*logMessage = STR_F(RemovePermissions_0, group);
		Permissions::RemovePlayerFromGroup(steamId, fgroup);
		success = true;
	}
	else
	{
		// забыли прописать действие
		*logMessage = STR_F(ErrorChangingPermissions___0, L"2");
		success = false;
	}
	return success;
}

// Load()
// загрузка плагина
void Load(void)
{
	if (SurvivalShopApi::Version() < 1.0)
		return;
	SurvivalShopApi::RegisterEquipmentType(L"SurvivalShopPermissions", L"permissions", &PermissionsEquip);
}

// Unload
// выгрузка плагина
void Unload(void)
{
	if (SurvivalShopApi::Version() < 1.0)
		return;
	SurvivalShopApi::UnregisterEquipmentType(L"permissions");
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
