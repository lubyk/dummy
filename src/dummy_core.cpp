/**
 *
 * MACHINE GENERATED FILE. DO NOT EDIT.
 *
 * Bindings for library dummy
 *
 * This file has been generated by dub 2.1.~.
 */
#include "dub/dub.h"
#include "dummy/dummy.h"

using namespace dummy;

extern "C" {
int luaopen_dummy_Dummy(lua_State *L);
}

// --=============================================== FUNCTIONS
// Functions from namespace dummy
static const struct luaL_Reg dummy_functions[] = {
  { NULL, NULL},
};


extern "C" int luaopen_dummy_core(lua_State *L) {
  luaopen_dummy_Dummy(L);

  // Create the table which will contain all the constants
  lua_getfield(L, LUA_GLOBALSINDEX, "dummy");
  if (lua_isnil(L, -1)) {
    // no global table called dummy
    lua_pop(L, 1);
    lua_newtable(L);
    // <lib>
    lua_pushvalue(L, -1);
    // <lib> <lib>
    // _G.dummy = <lib>
    lua_setglobal(L, "dummy");
    // <lib>
  }
  // <lib>
  luaL_register(L, NULL, dummy_functions);
  // <lib>
  lua_pop(L, 1);
  return 0;
}
