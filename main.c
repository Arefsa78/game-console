//
// Created by Aref on 19/06/29.
//
#include <stdio.h>
#include <malloc.h>
#include "game.h"

int main() {
    Game *game = (Game *) malloc(sizeof(Game));
    init_game(game, game_name); //input
    run_game(game);
    ini
}