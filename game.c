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

//struct Point *get_dir(char point, struct Map map) {
//    int y1 = 0;
//    int x1 = 0;
//    int y2 = map->height;
//    int x2 = map->width;
//    struct Point dir;
//
//    for (; x1 <= x2; x1++) {
//        for (; y1 <= y2; y1++) {
//            if (map->field[x1][y1] == point) {
//                dir->X = x1 - 1;
//                dir->y = y1 - 1;
//            }
//        }
//    }
//
//    return dir;
//}

//void best_move(Game *game, struct Point dir, struct Map map) {
//    int oppx = game->opps.x;
//    int oppy = game->opps.y;
//    int distx = abs(oppx - dir.x);
//    int disty = abs(oppy - dir.y);
//    char **mapdir = map->field;
//
//    if (oppx =<dir.x){
//        if (oppy <= dir.y) {
//            if (distx <= disty) {
//                if (mapdir[oppx + 1][oppy] == ' ') {
//                    //move right
//                }
//                if (mapdir[oppx + 1][oppy] == MoveBlock.name) {
//                    //move both right
//                }
//                continue;
//            } else {
//                if (mapdir[oppx][oppy + 1] == ' ') {
//                    //move up
//                }
//                if (mapdir[oppx][oppy + 1] == Moveblock.name) {
//                    //move both up
//                }
//                continue;
//            }
//            else{
//                if (distx <= disty) {
//                    if (mapdir[oppx + 1][oppy] == ' ') {
//                        //move right
//                    }
//                    if (mapdir[oppx + 1][oppy] == MoveBlock.name) {
//                        //move both right
//                    }
//                    continue;
//                } else {
//                    if (mapdir[oppx][oppy - 1] == ' ') {
//                        //move down
//                    }
//                    if (mapdir[oppx][oppy - 1] == MoveBlock.name) {
//                        //move both down
//                    }
//                    continue;
//                }
//
//            }
//        } else {
//            if (oppy <= dir.y) {
//                if (distx <= disty) {
//                    if (mapdir[oppx - 1][oppy] == ' ') {
//                        //move left
//                    }
//                    if (mapdir[oppx - 1][oppy] == MoveBlock.name) {
//                        //move both left
//                    }
//                    continue;
//                } else {
//                    if (mapdir[oppx][oppy + 1] == ' ') {
//                        //move up
//                    }
//                    if (mapdir[oppx][oppy + 1] == Moveblock.name) {
//                        //move both up
//                    }
//                    continue;
//                }
//                else{
//                    if (distx <= disty) {
//                        if (mapdir[oppx - 1][oppy] == ' ') {
//                            //move left
//                        }
//                        if (mapdir[oppx - 1][oppy] == MoveBlock.name) {
//                            //move both left
//                        }
//                        continue;
//                    } else {
//                        if (mapdir[oppx][oppy - 1] == ' ') {
//                            //move down
//                        }
//                        if (mapdir[oppx][oppy - 1] == MoveBlock.name) {
//                            //move both down
//                        }
//                        continue;
//                    }
//
//                }
//            }
//        }
//    }
//
//}

//void opps_decision(Game *game) {
//
//    char point;
//    point = opp.target;
//    struct Point dir = get_dir(opp.name, point, game->map);
//    opp.move = best_move(game, dir, game->map);
//}

void next_frame(Game *game) {
    opps_decision(game);
    move_object(game->player, game);
    opps_move(game);
    raindbs_move(game);
    make_raindb(game);
}

void opps_move(Game *game) {
    Vector *opps = game->opps;
    for (Vector *it = opps; it != NULL; it = it->next) {
        Object *opp = (Object *) it->data;
        choose_dir(opp, find_nearest(game->map, opp->point, game->rule->opp.target), game);
        move_object(opp, game);
    }
}

void init_game_with_map(Game *game) {
    Map *map = game->map;
    Rule *rule = game->rule;
    for (int y = 0; y < map->height; y++) {
        for (int x = 0; x < map->width; x++) {
            char ob = (char) map->field[y][x];
            Object *new_obj = (Object *) malloc(sizeof(Object));
            new_obj->point = (Point) {x, y};
            new_obj->charecter = ob;
            if (ob == rule->solid_block) {
                Vector *new = pushback(game->solidBlocks, sizeof(Object));
                new->data = new_obj;
            }
            if (ob == rule->death_block) {
                Vector *new = pushback(game->deathBlocks, sizeof(Object));
                new->data = new_obj;
            }
            if (ob == rule->move_block) {
                Vector *new = pushback(game->move_blocks, sizeof(Object));
                new->data = new_obj;
            }
            if (ob == rule->wall) {
                Vector *new = pushback(game->walls, sizeof(Object));
                new->data = new_obj;
            }
            if (ob == rule->rpoints.charecter) {
                Vector *new = pushback(game->rpoints, sizeof(Object));
                new->data = new_obj;
            }
            if (ob == rule->opp.charecter) {
                Vector *new = pushback(game->opps, sizeof(Object));
                new->data = new_obj;
            }
            if (ob == rule->charecter) {
                game->player = *new_obj;
                free(new_obj);
            }
            if (ob == rule->object) {
                game->object = *new_obj;
                free(new_obj);
            }
            if (ob == rule->target) {
                game->target = *new_obj;
                free(new_obj);
            }
        }
    }
}

void raindbs_move(Game *game) {
    Vector* raindbs = game->raindbs;
    for(Vector* it = raindbs; it != NULL; it = it->next){
        Object* raindb = (Object*)it->data;
        move_object(raindb, game);
    }
}

void make_raindb(Game *game) {
    for(int i = 0; i < game->rule->raindb; i++){
        Object* new_db = (Object*)malloc(sizeof(Object));
        new_db->charecter = (char)game->rule->death_block;
        new_db->move_dir.move = (Point){0, 1};
        new_db->point = (Point){rand()%game->map->width, 0};
    }
}
