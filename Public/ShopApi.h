#pragma once

#include "Plugin.h"

#define SURVIVALSHOP_API __declspec(dllimport)

namespace SurvivalShopApi
{
	typedef bool(*EquipmentFunction)(const unsigned long long steamId, const web::json::value *customItem, std::wstring *logMessage);

	// RegisterCustom
	// получить версию Shop API
	SURVIVALSHOP_API float Version();

	// RegisterCustom
	// зарегистрировать собственный тип товара для применения в custom.json
	SURVIVALSHOP_API bool RegisterEquipmentType(const std::wstring pluginName, const std::wstring typeName, EquipmentFunction func);

	// RegisterCustom
	// удалить регистрацию собственного типа товаров
	SURVIVALSHOP_API void UnregisterEquipmentType(const std::wstring typeName);
}