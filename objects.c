//
// Created by Aref on 19/06/30.
//

#include "objects.h"
#include "rule.h"

void init_move(MoveAction *move, Point point, char r) {
    move->move = point;
    move->control = r;
}

void move_object(Object *obj, Map *map, Rule* rule) {
    Point new_pos = plus(obj->point, obj->move_dir.move);
    if(can_go(rule,(char)cell(map, new_pos)))
        obj->point = new_pos;
    if(die(rule, (char)cell(map, new_pos)))
        obj->point = INVALID_POINT; //DEAD :)
}

Point plus(Point a, Point b) {
    return (Point) {a.x + b.x, a.y + b.y};
}
