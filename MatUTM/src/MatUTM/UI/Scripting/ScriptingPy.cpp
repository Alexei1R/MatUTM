#include "mathpch.h"
#include "ScriptingLua.h"
#include <string>






namespace MatUTM {


	ScriptingLua::ScriptingLua()
	{
		L = luaL_newstate();
	}

	ScriptingLua::~ScriptingLua() {
		lua_close(L);
	}


	bool ScriptingLua::LuaExec() {
		luaL_dostring(L, m_LuaScriptData.c_str());
		return true;
	}

	double ScriptingLua::GetLuaVariable(const std::string &data) {
		lua_getglobal(L, data.c_str());

		lua_Number value = lua_tonumber(L,1);

		return value;
		
	}
	






}