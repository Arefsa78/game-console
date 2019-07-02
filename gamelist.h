//
// Created by Aref on 19/07/02.
//

#ifndef GAME_CONSOLE_GAMELIST_H
#define GAME_CONSOLE_GAMELIST_H

#include <dirent.h>
#include "vector.h"

int get_games(char *directory, Vector *game_list);
int choose_game(Vector* game_list);

#endif //GAME_CONSOLE_GAMELIST_H
