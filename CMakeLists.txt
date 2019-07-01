cmake_minimum_required(VERSION 3.13)
project(game_console C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(game_console
        etc.c
        etc.h
        game.c
        game.h
        main.c
        map.c
        map.h
        objects.c
        objects.h
        rule.c
        rule.h
        vector.c
        vector.h move.h run.c run.h)
