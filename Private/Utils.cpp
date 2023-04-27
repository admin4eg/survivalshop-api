////////////////////////////////////////////////////////////////
//
// SURVIVALSHOP API
// Plugin to add "permission" item to custom goods definitions
// util functions
// 
////////////////////////////////

#include "Plugin.h"

namespace Utils
{
	// ToLower(text)
	// convert string to lowercase
	std::wstring ToLower(const std::wstring& w)
	{
		const size_t size = w.size();
		std::wstring lstr;
		if (size > 0)
		{
			lstr.resize(size);
			for (std::wstring::size_type i = 0; i < w.length(); ++i)
			{
				auto c = w[i];
				if (c == L'�') c = L'�';
				else if (c == L'�') c = L'�';
				else if (c == L'�') c = L'�';
				else if (c == L'�') c = L'�';
				else if (c == L'�') c = L'�';
				else if (c == L'�') c = L'�';
				else if (c == L'�') c = L'�';
				else if (c == L'�') c = L'�';
				else if (c == L'�') c = L'�';
				else if (c == L'�') c = L'�';
				else if (c == L'�') c = L'�';
				else if (c == L'�') c = L'�';
				else if (c == L'�') c = L'�';
				else if (c == L'�') c = L'�';
				else if (c == L'�') c = L'�';
				else if (c == L'�') c = L'�';
				else if (c == L'�') c = L'�';
				else if (c == L'�') c = L'�';
				else if (c == L'�') c = L'�';
				else if (c == L'�') c = L'�';
				else if (c == L'�') c = L'�';
				else if (c == L'�') c = L'�';
				else if (c == L'�') c = L'�';
				else if (c == L'�') c = L'�';
				else if (c == L'�') c = L'�';
				else if (c == L'�') c = L'�';
				else if (c == L'�') c = L'�';
				else if (c == L'�') c = L'�';
				else if (c == L'�') c = L'�';
				else if (c == L'�') c = L'�';
				else if (c == L'�') c = L'�';
				else if (c == L'�') c = L'�';
				else if (c == L'�') c = L'�';
				else c = std::tolower(w[i]);
				lstr[i] = c;
			}
		}
		return lstr;
	}

	// ToWide(text)
	// convert string to wide string
	std::wstring ToWide(const std::string& text)
	{
		const size_t size = text.size();

		std::wstring wstr;
		if (size > 0)
		{
			wstr.resize(size);
			size_t convertedChars;
			mbstowcs_s(&convertedChars, &wstr[0], size + 1, text.c_str(), _TRUNCATE);
		}
		return wstr;
	}

	// ToNarrow(text)
	// convert wide string to string
	std::string ToNarrow(const std::wstring& w)
	{
		std::string s(w.begin(), w.end());
		return s;
	}

	// Split(string, symbol)
	// Util function to split sting by spec. sybmol
	std::vector<std::string> Split(std::string str, char sym)
	{
		std::stringstream test(str);
		std::string segment;
		std::vector<std::string> seglist;
		while (std::getline(test, segment, sym))
			seglist.push_back(segment);
		return seglist;
	}

	// MinutesToTimeString
	// convert minutes to time string
	std::wstring MinutesToTimeString(long long minutes, std::wstring years, std::wstring days, std::wstring hours, std::wstring minutes_s)
	{
		std::wstring time = L"";
		if (minutes > (365 * 24 * 60)) // years
		{
			auto y = minutes / (365 * 24 * 60);
			minutes = minutes - y * (365 * 24 * 60);
			if (time != L"")
				time = time + L", ";
			time = time + std::to_wstring(y) + L" " + years;
		}
		if (minutes > (24 * 60)) // ����
		{
			auto d = minutes / (24 * 60);
			minutes = minutes - d * (24 * 60);
			if (time != L"")
				time = time + L", ";
			time = time + std::to_wstring(d) + L" " + days;
		}
		if (minutes > 60) // �����
		{
			auto h = minutes / 60;
			minutes = minutes - h * 60;
			if (time != L"")
				time = time + L", ";
			time = time + std::to_wstring(h) + L" " + hours;
		}
		// �����
		if (time != L"")
			time = time + L", ";
		time = time + std::to_wstring(minutes) + L" " + minutes_s;
		return time;
	}
}