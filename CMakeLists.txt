cmake_minimum_required(VERSION 3.13)
project(game_console)

set(CMAKE_CXX_STANDARD 14)

add_executable(game_console
        README.md main.c rule.h rule.c etc.h etc.c)
