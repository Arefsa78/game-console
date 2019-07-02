//
// Created by Aref on 19/06/30.
//

#include <stdlib.h>
#include "map.h"
#include "etc.h"
#include <time.h>

int init_map(FILE *file, Map *map)
{
    char line[20];
    get_line(file, line);
    sscanf(line, "%dx%d", &(map->height), &(map->width));
    for (int height = 0; height < map->height; height++)
    {
        for (int width = 0; width < map->width; width++)
            map->field[height][width] = fgetc(file);
        fgetc(file);
    }
}

void test_init(Map *map, int height, int width)
{
    srand(time(0));
    map->width = width;
    map->height = height;
    map->field = (int **)malloc(sizeof(int *) * height);
    for (int i = 0; i < height; i++)
    {
        map->field[i] = (int *)malloc(sizeof(int) * width);
        for (int j = 0; j < width; j++)
            map->field[i][j] = (rand() % 26) + 'A';
    }
}

int cell(Map *map, Point x) {
    return map->field[x.y][x.x];
}
