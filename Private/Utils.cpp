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
				if (c == L'À') c = L'à';
				else if (c == L'Á') c = L'á';
				else if (c == L'Â') c = L'â';
				else if (c == L'Ã') c = L'ã';
				else if (c == L'Ä') c = L'ä';
				else if (c == L'Å') c = L'å';
				else if (c == L'¨') c = L'¸';
				else if (c == L'Æ') c = L'æ';
				else if (c == L'Ç') c = L'ç';
				else if (c == L'È') c = L'è';
				else if (c == L'É') c = L'é';
				else if (c == L'Ê') c = L'ê';
				else if (c == L'Ë') c = L'ë';
				else if (c == L'Ì') c = L'ì';
				else if (c == L'Í') c = L'í';
				else if (c == L'Î') c = L'î';
				else if (c == L'Ï') c = L'ï';
				else if (c == L'Ð') c = L'ð';
				else if (c == L'Ñ') c = L'ñ';
				else if (c == L'Ò') c = L'ò';
				else if (c == L'Ó') c = L'ó';
				else if (c == L'Ô') c = L'ô';
				else if (c == L'Õ') c = L'õ';
				else if (c == L'Ö') c = L'ö';
				else if (c == L'×') c = L'÷';
				else if (c == L'Ø') c = L'ø';
				else if (c == L'Ù') c = L'ù';
				else if (c == L'Ú') c = L'ú';
				else if (c == L'Û') c = L'û';
				else if (c == L'Ü') c = L'ü';
				else if (c == L'Ý') c = L'ý';
				else if (c == L'Þ') c = L'þ';
				else if (c == L'ß') c = L'ÿ';
				else c = std::tolower(w[i]);
				lstr[i] = c;
			}
		}
		return lstr;
	}
}