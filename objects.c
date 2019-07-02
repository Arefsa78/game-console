//
// Created by Aref on 19/06/30.
//

#include "objects.h"
#include "rule.h"
#include "game.h"

void init_move(MoveAction *move, Point point, char r) {
    move->move = point;
    move->control = r;
}

void move_object(Object *obj, Game *game) {
    Rule *rule = game->rule;
    Map *map = game->map;
    Point new_pos = plus_point(obj->point, obj->move_dir.move);
    if (can_go(rule, (char) cell(map, new_pos)))
        obj->point = new_pos;
    if (die(rule, (char) cell(map, new_pos)))
        obj->point = INVALID_POINT; //DEAD :)
    move_another(obj, game);
}

void move_another(Object *obj, Game *game) {
    Map *map = game->map;
    Rule *rule = game->rule;
    if(cell(map, obj->point) == rule->object){
        game->object.move_dir = obj->move_dir;
        move_object(&game->object, game);
        return;
    }
    for (Vector *it = game->move_blocks; it != NULL; it = it->next) {
        Object* block_obj = (Object *) it->data;
        if (same_point(block_obj->point, obj->point)) {
            block_obj->move_dir = obj->move_dir;
            move_object(block_obj, game);
            return;
        }
    }
}

Point plus_point(Point a, Point b) {
    return (Point) {a.x + b.x, a.y + b.y};
}

int same_point(Point a, Point b) {
    return a.x == b.x && a.y == b.y;
}

void choose_dir(Object *opp, Point target, Game *game) {

    opp->move_dir.move = INVALID_POINT;// tahesh bayad opp.move_dir ro avaz konii MERCIIIIII :)
}
