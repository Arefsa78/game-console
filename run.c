//
// Created by Aref on 19/07/01.
//

#include <time.h>
#include "run.h"
#include "move.h"

int run_game(Game *game) {
    clock_t  start_frame = clock();
    game->time.start_game = clock();
    while (clock() - game->time.start_game >= game->time.game_length){

        getkey(game);
        if(clock() - start_frame >= game->time.frame_length){
            next_frame(game);
            display(game);
            start_frame = clock();
        }
    }
    return 1;
}
