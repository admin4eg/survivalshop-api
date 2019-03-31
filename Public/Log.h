#pragma once

#include "Plugin.h"

#include <iostream>
#include <fstream>

#define SURVIVALHOST_API __declspec(dllimport)

namespace SHLog
{
	// Event(prefix, text, saveToLogfile)
	// Write event log message to console output and (optionally) to log file
	SURVIVALHOST_API void Event(const std::wstring& type, const std::wstring& text, bool saveToLogfile);

	// Error(prefix, text, saveToLogfile)
	// write a error log message to console output and (optionally) to log file
	SURVIVALHOST_API void Error(const std::string& plugin, const std::wstring& text, bool saveToLogfile);
}