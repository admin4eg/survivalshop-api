////////////////////////////////////////////////////////////////
//
// SURVIVALSHOP API
// Plugin to add "permission" item to custom goods definitions
// 
////////////////////////////////

#pragma once

#include <windows.h>

#ifdef ATLAS
	#define COMMON_ATLAS
	#define Common Atlas
	#include <API/Atlas/Atlas.h>
	#include "Atlas.h"
#else
	#define COMMON_ARK
	#define Common Ark
	#include <API/Ark/Ark.h>
	#include "Ark.h"
#endif

#include <API/UE/Math/ColorList.h>

#include <Tools.h>

#include <unordered_map>
#include <cpprest/http_client.h>

namespace Plugin
{
	extern std::string Name;
	extern std::string Version;
	extern std::string VersionState;
	extern std::string Credits;
}

#include "Strings.h"
#include "Log.h"