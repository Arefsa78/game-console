//
// Created by Aref on 19/06/30.
//

#include <stdlib.h>
#include "map.h"
#include "etc.h"
#include <time.h>
#include <conio.h>

int init_map(FILE *file, Map *map) {
    char line[20];
    get_line(file, line);
    sscanf(line, "%dx%d", &(map->height), &(map->width));
    map->field = (int **) malloc(sizeof(int *) * map->height);
    for (int height = 0; height < map->height; height++) {
        map->field[height] = (int *) malloc(sizeof(int) * map->width);
        for (int width = 0; width < map->width; width++) {
            map->field[height][width] = fgetc(file);
        }
        fgetc(file);
    }
}

void test_init(Map *map, int height, int width) {
    map->width = width;
    map->height = height;
    map->field = (int **) malloc(sizeof(int *) * height);
    for (int i = 0; i < height; i++) {
        map->field[i] = (int *) malloc(sizeof(int) * width);
        for (int j = 0; j < width; j++)
            map->field[i][j] = (rand() % 26) + 'A';
    }
}

int cell(Map *map, Point x) {
    if (same_point(x, INVALID_POINT))
        return ' ';
    return map->field[x.y][x.x];
}

Point find_nearest(Map *map, Point start, char c) {
    double min_dist = 1000;
    Point res = INVALID_POINT;
    for (int i = 0; i < map->height; i++)
        for (int j = 0; j < map->width; j++) {
            Point pos = (Point) {j, i};
            double d = dist(start, pos);
            if (map->field[i][j] == c && d < min_dist) {
                res = (Point) {j, i};
                min_dist = d;
            }
        }
    return res;
}

int dist(Point a, Point b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

void display_map(Map *map) {
    for (int y = 0; y < map->height; y++) {
        for (int x = 0; x < map->width; x++) {
            printf("%c", map->field[y][x]);
        }
        printf("\n");
    }
}

void random_point(Map *map, Rule *rule, Object *obj) {
    int x = rand() % map->width;
    int y = rand() % map->height;
    while (is_obj(rule, (char) cell(map, (Point) {x, y}))) {
        x = rand() % map->width;
        y = rand() % map->height;
    }
    obj->point = (Point) {x, y};
}

int is_in_area(Map *map, Point x) {
    if(x.x < 0)
        return 0;
    if(x.x >= map->width)
        return 0;
    if (x.y < 0)
        return 0;
    if (x.y >= map->height)
        return 0;
    return 1;
}
