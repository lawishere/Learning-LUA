
#include <stdio.h>
#include <string.h>
#include <lua5.2/lua.h>
#include <lua5.2/lauxlib.h>
#include <lua5.2/lualib.h>

int main (void) {
    char buff[256];
    int error;
    lua_State *L = luaL_newstate();   /* opens Lua */
    luaL_openlibs(L);             /* opens the basic library */

    while (fgets(buff, sizeof(buff), stdin) != NULL) {
        error = luaL_loadbuffer(L, buff, strlen(buff), "line") ||
                lua_pcall(L, 0, 0, 0);
        if (error) {
            fprintf(stderr, "%s", lua_tostring(L, -1));
            lua_pop(L, 1);  /* pop error message from the stack */
        }
    }

    lua_close(L);
    return 0;
}
