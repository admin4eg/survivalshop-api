////////////////////////////////////////////////////////////////
//
// SURVIVALSHOP API
// Plugin to add "permission" item to custom goods definitions
// util functions
// 
////////////////////////////////

#pragma once

#include "Plugin.h"

namespace Utils
{
	// ToLower(text)
	// convert string to lowercase
	std::wstring ToLower(const std::wstring& w);

	// ToLower(text)
	// convert string to lowercase
	wchar_t ToLower(const wchar_t c);

	// ToWide(text)
	// convert string to wide string
	std::wstring ToWide(const std::string& text);

	// ToNarrow(text)
	// convert wide string to string
	std::string ToNarrow(const std::wstring& w);

	// Split(string, symbol)
	// Util function to split sting by spec. sybmol
	std::vector<std::string> Split(std::string str, char sym);

	// MinutesToTimeString
	// convert minutes to time string
	std::wstring MinutesToTimeString(long long minutes, std::wstring years, std::wstring days, std::wstring hours, std::wstring minutes_s);
}