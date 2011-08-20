#include "common.h"
#include <lua.hpp>
#include "InstanceList.h"
#include "PseuWoW.h"
#include "log.h"
#include "LuaPackage.h"

LuaPackage::LuaPackage(PseuInstance *parent) :
  _parent(parent)
{
	_L = luaL_newstate();
	luaL_openlibs(_L);
	lua_register(_L,"abort",LuaPackage::luafn_abort);
	lua_register(_L,"print",LuaPackage::luafn_print);
	lua_register(_L,"quit",	LuaPackage::luafn_quit);
}

LuaPackage::~LuaPackage()
{
	lua_close(_L);
}

int LuaPackage::luafn_abort(lua_State *L)
{
	InstanceList::get()->abortproc();
	return 0;
}

int LuaPackage::luafn_print(lua_State *L)
{
	logcustom(0, LGREEN, lua_tostring(L,1));
	return 0;
}

int LuaPackage::luafn_quit(lua_State *L)
{
	InstanceList::get()->quitproc();
	return 0;
}
