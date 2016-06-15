//
// Created by frank on 6/15/16.
//

#ifndef LEARNING_LUA_COMMON_H
#define LEARNING_LUA_COMMON_H
#if defined(__cplusplus)
extern "C" {
#endif

#include <lua5.2/lua.h>
#include <lua5.2/lauxlib.h>
#include <lua5.2/lualib.h>

extern void
StackDump (lua_State *L);

#if defined(__cplusplus)
}
#endif
#endif //LEARNING_LUA_COMMON_H
