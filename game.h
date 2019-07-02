//
// Created by Aref on 19/06/30.
//

#ifndef GAME_CONSOLE_GAME_H
#define GAME_CONSOLE_GAME_H

#include "rule.h"
#include "map.h"
#include "objects.h"
#include "vector.h"

typedef struct Game Game;

struct Game {
    Rule *rule;
    Map *map;
    Vector *solidBlocks;
    Vector *deathBlocks;
    Vector *raindbs;
    Vector *move_blocks;
    Vector *walls;
    Vector *rpoints;
    Vector *opps;

    Object player;
    Object target;
    Object object;

    Time time;

    int score;
};

void init_game(Game *game, char *game_name);

void init_game_with_map(Game* game);

void next_frame(Game *game);

void opps_move(Game* game);

void opps_decision(Game *game);
#endif //GAME_CONSOLE_GAME_H
