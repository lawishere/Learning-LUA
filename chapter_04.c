//
// Created by frank on 6/17/16.
//

#include "common.h"


#define MAX_COLOR       255


/* assume that table is on the stack top */
int getfield (lua_State *L, const char *key) {
    int result;
    lua_pushstring(L, key);
    lua_gettable(L, -2);  /* get background[key] */
    if (!lua_isnumber(L, -1))
        error(L, "invalid component in background color");
    result = (int)lua_tonumber(L, -1) * MAX_COLOR;
    lua_pop(L, 1);  /* remove number */
    return result;
}

int main(int argc, char *argv)
{
    lua_State *L = luaL_newstate();
    luaL_openlibs(L);
    int red, green, blue;

    if (luaL_loadfile(L, "2.lua") || lua_pcall(L, 0, 0, 0))
        error(L, "cannot run configuration file: %s",
              lua_tostring(L, -1));

    lua_getglobal(L, "background");
    if (!lua_istable(L, -1))
        error(L, "`background' is not a valid color table");

    red = getfield(L, "r");
    green = getfield(L, "g");
    blue = getfield(L, "b");

    printf("red = %d, green = %d, blue = %d\r\n",
        red, green, blue);

    lua_close(L);
    return 0;
}
