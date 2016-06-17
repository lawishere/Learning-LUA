cmake_minimum_required(VERSION 2.8)
project(Learning_LUA)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
#set(CMAKE_LINK_LIBRARY_FLAG  "${CMAKE_LINK_LIBRARY_FLAG}" lua5.2)
#set(CMAKE_C_LINK_EXECUTABLE lua5.2)

set(PUBLIC
        common.h common.c)

foreach(var RANGE 1 5)
    set(CHAPTER chapter_0${var}.c ${PUBLIC})
    add_executable(chapter_0${var} ${CHAPTER})
    target_link_libraries(chapter_0${var} lua5.2)
endforeach()