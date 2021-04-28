#pragma once
#include <string>
#include "Lua.h"
#include "FileSystem.h"
#include "Mouse-Keyboard.h"

using namespace CallCheck;

int GetGenv(int rL) {
	r_pushvalue(rL, LUA_GLOBALSINDEX);
	return 1;
}

int GetSenv(int rL) {
	r_pushvalue(rL, LUA_ENVIRONINDEX);
	return 1;
}

int GetRenv(int rL) {
	r_pushvalue(rL, LUA_GLOBALSINDEX);
	return 1;
}

int GetReg(int rL) {
	r_pushvalue(rL, LUA_REGISTRYINDEX);
	return 1;
}

int DebugGetReg(int rL) {
	r_pushvalue(rL, -10000);
	return 1;
}

int Loadstring(int rL) {
	std::string Script = r_tostring(rL, 1, 0);
	Execute(rL, Script);
	return 0;
}

int HttpGet(int rL) {
	std::string Content = DownloadUrl(r_tolstring(rL, 1, 0));
        r_pushlstring(rL, Content.c_str(), Content.size());
        return 1;
}

void RegisterLuaFunctions() {

	RegisterMouseKeyboard();
	RegisterFileSystem();

	RegisterFunction(rL, reinterpret_cast<int>(GetGenv), "getgenv");
	RegisterFunction(rL, reinterpret_cast<int>(GetRenv), "getrenv");
	RegisterFunction(rL, reinterpret_cast<int>(GetSenv), "getsenv");
	RegisterFunction(rL, reinterpret_cast<int>(GetReg), "getreg");
	RegisterFunction(rL, reinterpret_cast<int>(Loadstring), "loadstring");
        RegisterFunction(rL, reinterpret_cast<int>(HttpGet), "HttpGet");

}
