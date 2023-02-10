#pragma once
#include "MathUTM.h"
#include "lua/lua.hpp"



namespace MatUTM {


	class ScriptingLua {
	public:
		ScriptingLua();
		~ScriptingLua();


	public:

		void SetLuaScriptDataString(const char* data) { m_LuaScriptData = data; };



	public:
		double GetLuaVariable(const std::string &data);


		bool LuaExec();



	private:
		//Lua variables
		lua_State* L;






		//My variables
	private:
		std::string m_LuaScriptData;

	};
}