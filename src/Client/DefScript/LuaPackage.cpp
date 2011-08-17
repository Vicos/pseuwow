#include <lua.hpp>
#include "LuaPackage.h"

LuaPackage::LuaPackage()
{
	this->luaVM = luaL_newstate();
	/* if( luaVM == NULL )
		logcritical ("Lua machine can't initialize");
		*/
	luaL_openlibs(this->luaVM);
}

LuaPackage::~LuaPackage()
{
	lua_close(this->luaVM);
}
