//
// Created by frank on 6/15/16.
//
#include "common.h"

int main(int argc, char *argv)
{
    lua_State *L = luaL_newstate();
    luaL_openlibs(L);
    int width = 0;
    int height = 0;

    if (luaL_loadfile(L, "1.lua") || lua_pcall(L, 0, 0, 0))
        error(L, "cannot run configuration file: %s",
              lua_tostring(L, -1));

    lua_getglobal(L, "width");
    lua_getglobal(L, "height");
    if (!lua_isnumber(L, -2))
        error(L, "`width' should be a number\n");
    if (!lua_isnumber(L, -1))
        error(L, "`height' should be a number\n");

    width = (int)lua_tonumber(L, -2);
    height = (int)lua_tonumber(L, -1);

    printf("widt = %d, height = %d\r\n", width, height);

    lua_close(L);
    return 0;
}
