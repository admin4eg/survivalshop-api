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
				if (c == L'А') c = L'а';
				else if (c == L'Б') c = L'б';
				else if (c == L'В') c = L'в';
				else if (c == L'Г') c = L'г';
				else if (c == L'Д') c = L'д';
				else if (c == L'Е') c = L'е';
				else if (c == L'Ё') c = L'ё';
				else if (c == L'Ж') c = L'ж';
				else if (c == L'З') c = L'з';
				else if (c == L'И') c = L'и';
				else if (c == L'Й') c = L'й';
				else if (c == L'К') c = L'к';
				else if (c == L'Л') c = L'л';
				else if (c == L'М') c = L'м';
				else if (c == L'Н') c = L'н';
				else if (c == L'О') c = L'о';
				else if (c == L'П') c = L'п';
				else if (c == L'Р') c = L'р';
				else if (c == L'С') c = L'с';
				else if (c == L'Т') c = L'т';
				else if (c == L'У') c = L'у';
				else if (c == L'Ф') c = L'ф';
				else if (c == L'Х') c = L'х';
				else if (c == L'Ц') c = L'ц';
				else if (c == L'Ч') c = L'ч';
				else if (c == L'Ш') c = L'ш';
				else if (c == L'Щ') c = L'щ';
				else if (c == L'Ъ') c = L'ъ';
				else if (c == L'Ы') c = L'ы';
				else if (c == L'Ь') c = L'ь';
				else if (c == L'Э') c = L'э';
				else if (c == L'Ю') c = L'ю';
				else if (c == L'Я') c = L'я';
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
		if (minutes > (24 * 60)) // дней
		{
			auto d = minutes / (24 * 60);
			minutes = minutes - d * (24 * 60);
			if (time != L"")
				time = time + L", ";
			time = time + std::to_wstring(d) + L" " + days;
		}
		if (minutes > 60) // часов
		{
			auto h = minutes / 60;
			minutes = minutes - h * 60;
			if (time != L"")
				time = time + L", ";
			time = time + std::to_wstring(h) + L" " + hours;
		}
		// минут
		if (time != L"")
			time = time + L", ";
		time = time + std::to_wstring(minutes) + L" " + minutes_s;
		return time;
	}
}