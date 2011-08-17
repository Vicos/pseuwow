#include "common.h"
#include <lua.hpp>
#include "InstanceList.h"
#include "PseuWoW.h"
#include "LuaPackage.h"

LuaPackage::LuaPackage(PseuInstance *parent) :
  _parent(parent)
{
	_L = luaL_newstate();
	luaL_openlibs(_L);
	lua_register(_L,"quit",LuaPackage::luafn_quit);
}

LuaPackage::~LuaPackage()
{
	lua_close(_L);
}

int LuaPackage::luafn_quit(lua_State *L)
{
	InstanceList::get()->quitproc();
	return 0;
}