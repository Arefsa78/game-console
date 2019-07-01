//
// Created by Aref on 19/06/30.
//

#ifndef GAME_CONSOLE_OBJECTS_H
#define GAME_CONSOLE_OBJECTS_H

typedef struct Point Point;
typedef struct Object Object;
typedef struct MoveAction MoveAction;
typedef struct Time Time;
typedef struct AttackAction AttackAction;

struct Point{
    int x;
    int y;
};

struct Object{
    Point point;
    char charecter;
};

struct MoveAction{
    char control;
    Point move;
};

struct AttackAction{
    char control;
    int range;
    int flag;
};

struct Time{
    float game_length;
    float frame_length;
};

#endif //GAME_CONSOLE_OBJECTS_H
