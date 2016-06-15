
#include <stdio.h>
#include <string.h>
#include <lua5.2/lua.h>
#include <lua5.2/lauxlib.h>
#include <lua5.2/lualib.h>
#include "common.h"

int main (void) {
    lua_State *L = luaL_newstate();

    lua_pushboolean(L, 1);
    lua_pushnumber(L, 10);
    lua_pushnil(L);
    lua_pushstring(L, "hello");

    StackDump(L);
    /* true  10  nil  `hello'  */

    lua_pushvalue(L, -4);
    StackDump(L);
    /* true  10  nil  `hello'  true  */

    lua_replace(L, 3);
    StackDump(L);
    /* true  10  true  `hello'  */

    lua_settop(L, 6);
    StackDump(L);
    /* true  10  true  `hello'  nil  nil  */

    lua_remove(L, -3);
    StackDump(L);
    /* true  10  true  nil  nil  */

    lua_settop(L, -5);
    StackDump(L);
    /* true  */

    lua_close(L);
    return 0;
}
