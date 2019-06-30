//
// Created by Aref on 19/06/30.
//

#ifndef GAME_CONSOLE_GAME_H
#define GAME_CONSOLE_GAME_H

#include "rule.h"
#include "map.h"
#include "objects.h"
#include "vector.h"

struct Game{
    Rule* rule;
    Map* map;
    Vector solidBlock;
};

#endif //GAME_CONSOLE_GAME_H
