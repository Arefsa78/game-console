//
// Created by Aref on 19/06/30.
//

#include "map.h"
#include "etc.h"

int set_map(Map *map, FILE *file) {
    char line[20];
    get_line(file, line);
    sscanf(line, "%dx%d", &(map->height), &(map->width));
    for(int height = 0; height < map->height; height++){
        for(int width = 0; width < map->width; width++)
            map->field[height][width] = fgetc(file);
        fgetc(file);
    }
}