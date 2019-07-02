//
// Created by Aref on 19/07/01.
//

#include <time.h>
#include "run.h"
#include "move.h"
#include "etc.h"

int run_game(Game *game) {
    clock_t  start_frame = clock();
    game->time.start_game = clock();
    while (clock() - game->time.start_game <= game->time.game_length){

        getkey(game);
        if(clock() - start_frame >= game->time.frame_length){

            db(frame);
            next_frame(game);
            display(game);
            if(game->game_over) {
                db(over);
                end_game(game);
                game = NULL;
                break;
            }
            start_frame = clock();
            display_point(game->player.point);
            display_point(game->player.move_dir.move);
            printf("rule: %c\n", game->rule->exit);
            printf("rain: %d\n", game->rule->raindb);
        }
    }
    if(game == NULL)
        return 1;
    end_game(game);
    return 1;
}

void display(Game *game) {
    display_map(game->map);
}
