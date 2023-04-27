#pragma once

#include "Plugin.h"

#define SURVIVALSHOP_API __declspec(dllimport)

namespace SurvivalShopApi
{
	typedef bool(*EquipmentFunction)(const unsigned long long steamId, const web::json::value *customItem, std::wstring *logMessage);
	typedef void(*TimerFunction)(const unsigned long long id, unsigned long long steamId, const std::wstring *data, const std::wstring *auxData, const std::wstring *comment, std::wstring *playerMessage);

	// RegisterCustom
	// get shop api version
	SURVIVALSHOP_API float Version();

	// GetLastError
	// get last error
	SURVIVALSHOP_API std::wstring GetLastError();

	// RegisterEquipmentType
	// register a custom goods type
	SURVIVALSHOP_API bool RegisterEquipmentType(const std::wstring pluginName, const std::wstring typeName, EquipmentFunction func);

	// UnregisterEquipmentType
	// register a custom goods type
	SURVIVALSHOP_API void UnregisterEquipmentType(const std::wstring typeName);

	// RegisterTimerType
	// register a timer function, the function is called when timer ends
	SURVIVALSHOP_API bool RegisterTimerType(const std::wstring pluginName, const std::wstring timerType, TimerFunction func);

	// UnregisterTimerType
	// register a timer function, the function is called when timer ends
	SURVIVALSHOP_API void UnregisterTimerType(const std::wstring timerType);

	// SetTimer
	// set a timer for a player
	SURVIVALSHOP_API bool SetTimer(const std::wstring timerName, const unsigned long long steamId, const std::wstring data, const std::wstring auxData, const std::wstring comment, long minutes);
}