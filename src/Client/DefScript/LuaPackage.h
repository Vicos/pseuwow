#ifndef LUAPACKAGE_H
#define LUAPACKAGE_H

#include <string>
#include <lua.hpp>
#include "PseuWoW.h"

class PseuInstance;

class LuaPackage
{
	public:
		LuaPackage(PseuInstance *parent);
		~LuaPackage();

		int dostring(const char *str) { return luaL_dostring(_L,str); };
		
		lua_State* getLuaVM(void) { return _L; };

	private:
		static int luafn_abort(lua_State *L);
		static int luafn_quit(lua_State *L);

	private:
		PseuInstance *_parent;
		lua_State* _L;
};

#endif
