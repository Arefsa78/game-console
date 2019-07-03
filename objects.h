//
// Created by Aref on 19/06/30.
//

#ifndef GAME_CONSOLE_OBJECTS_H
#define GAME_CONSOLE_OBJECTS_H

#include <time.h>

#define INVALID_POINT (Point){-100, -100}

typedef struct Point Point;
typedef struct Object Object;
typedef struct MoveAction MoveAction;
typedef struct Time Time;
typedef struct AttackAction AttackAction;

struct Point {
    int x;
    int y;
};

struct MoveAction {
    char control;
    Point move;
};

struct Object {
    Point point;
    char charecter;
    MoveAction move_dir;
};

struct AttackAction {
    char control;
    int range;
    int flag;
};

struct Time {
    float game_length;
    float frame_length;
    clock_t start_game;
};

void init_move(MoveAction *move, Point point, char r);

Point plus_point(Point a, Point b);

int same_point(Point a, Point b);

void display_point(Point p);


#endif //GAME_CONSOLE_OBJECTS_H
