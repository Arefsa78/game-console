//
// Created by Aref on 19/06/29.
//
#include <stdio.h>
#include <malloc.h>
#include <dirent.h>
#include <conio.h>

#include "game.h"
#include "vector.h"
#include "gamelist.h"
#include "run.h"
#include "etc.h"

int main() {
    while (1) {
        Vector *game_list = NULL;
        game_list = pushback(game_list, 0);
        if (!get_games(LOCAL_DIR, game_list)) {
            printf("Game Directory not found!");
            return 0;
        }

        int n = choose_game(game_list);

        Game *game = (Game *) malloc(sizeof(Game));
        db(game);
        init_game(game, (char *) index(game_list, n, sizeof(char *)));
        run_game(game);
        free_vector(game_list);
    }
}