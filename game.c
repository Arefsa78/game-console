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
}

void next_frame(Game *game) {
    move_object(game->player,game->map, game->rule);

}
