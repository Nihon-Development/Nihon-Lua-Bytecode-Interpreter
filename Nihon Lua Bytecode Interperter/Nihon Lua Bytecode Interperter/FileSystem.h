#pragma once
#include "Lua.h"
#include "CallCheck.h"
#include <string>
#include <filesystem>

using namespace std;
using namespace CallCheck;

string GetDllPath(const char* Addon)
{
	HMODULE hModule = GetModuleHandleA("Nihon Lua Bytecode Interperter.dll");
	if (hModule == NULL) return "";
	char buffer[MAX_PATH + 1];
	GetModuleFileNameA(hModule, buffer, MAX_PATH);
	std::string::size_type pos = std::string(buffer).find_last_of("\\/");
	string file = std::string(buffer).substr(0, pos).append("\\Workspace\\").append(Addon);
	if (!file.empty())
		return file;
	return "error";
}

void RegisterFileSystem() {

}