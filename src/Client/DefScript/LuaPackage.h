#ifndef LUAPACKAGE_H
#define LUAPACKAGE_H

#include <string>
#include <lua.hpp>

class LuaPackage
{
	public:
		LuaPackage();
		~LuaPackage();

		int dostring(const char *str) { return luaL_dostring(this->luaVM,str); };
		
		lua_State* getLuaVM(void) { return this->luaVM; };

	private:

	private:
		lua_State* luaVM;
};

#endif
