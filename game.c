//
// Created by Aref on 19/06/30.
//

#include <malloc.h>
#include <string.h>
#include "game.h"

void init_game(Game *game, char *game_name) {
    game->rule = (Rule *) malloc(sizeof(Rule) * 1);
    game->map = (Map *) malloc(sizeof(Map) * 1);

    FILE *rules_file = fopen(strcat("game-", game_name), "r");
    FILE *map_file = fopen(strcat("map-", game_name), "r");

    init_rule(rules_file, game->rule);
    init_map(map_file, game->map);
    init_game_with_map(game);
}

void next_frame(Game *game) {
    opps_decision(game);
    move_object(game->player, game);
    opps_move(game);
}

void opps_move(Game *game) {
    Vector* opps = game->opps;
    for(Vector* it = opps; it != NULL; it = it->next){
        Object* opp = (Object*)it->data;
        move_object(opp, game);
    }
}

void init_game_with_map(Game *game) {
    
}
