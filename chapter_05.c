//
// Created by frank on 6/17/16.
//


#include "common.h"


/* call a function `f' defined in Lua */
double f (lua_State *L, double x, double y) {

    double z;

    /* push functions and arguments */
    lua_getglobal(L, "f");  /* function to be called */
    lua_pushnumber(L, x);   /* push 1st argument */
    lua_pushnumber(L, y);   /* push 2nd argument */

    /* do the call (2 arguments, 1 result) */
    if (lua_pcall(L, 2, 1, 0) != 0)
        error(L, "error running function `f': %s",
              lua_tostring(L, -1));

    /* retrieve result */
    if (!lua_isnumber(L, -1))
        error(L, "function `f' must return a number");
    z = lua_tonumber(L, -1);
    lua_pop(L, 1);  /* pop returned value */
    return z;

}

int main(int argc, char *argv)
{

    lua_State *L = luaL_newstate();

    /* do the call (2 arguments, 1 result) */
    if (luaL_loadfile(L, "3.lua") || lua_pcall(L, 0, 0, 0) != 0)
        error(L, "error running function `f': %s",
              lua_tostring(L, -1));


    printf("Result = %f\r\n", f(L, 9.11, 9.5));

    lua_close(L);
    return 0;
}
