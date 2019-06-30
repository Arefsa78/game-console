//
// Created by Aref on 19/06/30.
//

#ifndef GAME_CONSOLE_MAP_H
#define GAME_CONSOLE_MAP_H

#include <stdio.h>

typedef struct Map Map;

struct Map {
    int width;
    int height;
    int **field;
};

int init_map(FILE *file, Map *map);
void test_init(Map* map, int height, int width);

#endif //GAME_CONSOLE_MAP_H
