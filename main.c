//
// Created by Aref on 19/06/29.
//
#include <stdio.h>
#include <malloc.h>
#include <dirent.h>

#include "game.h"
#include "vector.h"
#include "gamelist.h"
#include "run.h"

int main() {
    Vector* game_list = NULL;
    if(!show_games("Games/", game_list)){
        printf("Game Directory not found!");
        return 0;
    }

    int n = choose_game(game_list);

    Game* game =  (Game*)malloc(sizeof(Game));
    init_game(game, (char*)index(game_list, n, sizeof(char*)));
    run_game(game);
}