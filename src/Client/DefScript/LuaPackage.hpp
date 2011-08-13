#ifndef LUAPACKAGE_HPP
#define LUAPACKAGE_HPP

#include <string>

extern "C" {
#include <lua5.1/lua.h>
#include <lua5.1/lualib.h>
#include <lua5.1/lauxlib.h>
}

class LuaPackage
{
	public:
		LuaPackage();
		~LuaPackage();

		int dostring(char *str) { return luaL_dostring(this->luaVM,str); };
		int dostring(std::string str) { return this->dostring(str.c_str()); };
		
		lua_State* getLuaVM(void) { return this->luaVM; };
	private:
	private:
		lua_State* luaVM;
};

#endif
