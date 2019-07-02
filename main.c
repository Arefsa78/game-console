//
// Created by Aref on 19/06/29.
//
#include <stdio.h>
#include <malloc.h>
#include <dirent.h>

#include "game.h"
#include "vector.h"
#include "gamelist.h"

int main() {
    Vector* game_list = NULL;
    show_games("Games/", game_list);

    int n = choose_game(game_list);

    init_game();
}