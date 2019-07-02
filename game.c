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

struct Point *get_dir(char point, struct Map map){
    int y1=0;
    int x1=0;
    int y2=map->height;
    int x2=map->width;
    struct Point dir;

    for(;x1<=x2;x1++){
        for(;y1<=y2;y1++){
            if(map->field[x1][y1]== point){
                dir->X=x1-1;
                dir->y=y1-1;
            }
        }
    }

    return dir;
}

void best_move(Game *game, struct Point dir, struct Map map){
    int oppx=game->opps.x;
    int oppy=game->opps.y;
    int distx= abs(oppx-dir.x);
    int disty=abs(oppy-dir.y);
    char** mapdir=map->field;

    if(oppx=<dir.x){
        if(oppy<=dir.y){
            if(distx<=disty){
                if(mapdir[oppx+1][oppy]==' '){
                    //move right
                }
                if(mapdir[oppx+1][oppy]==MoveBlock.name){
                    //move both right
                }
                continue;
            }
            else{
                if(mapdir[oppx][oppy+1]==' '){
                    //move up
                }
                if(mapdir[oppx][oppy+1]==Moveblock.name){
                    //move both up
                }
                continue;
            }
        else{
            if(distx<=disty){
                if(mapdir[oppx+1][oppy]==' '){
                    //move right
                }
                if(mapdir[oppx+1][oppy]==MoveBlock.name){
                    //move both right
                }
                continue;
            }
            else{
                if(mapdir[oppx][oppy-1]==' '){
                    //move down
                }
                if(mapdir[oppx][oppy-1]==MoveBlock.name){
                    //move both down
                }
                continue;
            }

        }
        }
    else{
        if(oppy<=dir.y){
            if(distx<=disty){
                if(mapdir[oppx-1][oppy]==' '){
                    //move left
                }
                if(mapdir[oppx-1][oppy]==MoveBlock.name){
                    //move both left
                }
                continue;
            }
            else{
                if(mapdir[oppx][oppy+1]==' '){
                    //move up
                }
                if(mapdir[oppx][oppy+1]==Moveblock.name){
                    //move both up
                }
                continue;
            }
        else{
            if(distx<=disty){
                if(mapdir[oppx-1][oppy]==' '){
                    //move left
                }
                if(mapdir[oppx-1][oppy]==MoveBlock.name){
                    //move both left
                }
                continue;
            }
            else{
                if(mapdir[oppx][oppy-1]==' '){
                    //move down
                }
                if(mapdir[oppx][oppy-1]==MoveBlock.name){
                    //move both down
                }
                continue;
            }

        }
        }
    }
    }

}

void opps_decision(Game *game){

    char point;
    point=opp.target;
    struct Point dir=get_dir(opp.name,point,game->map);
    opp.move=best_move(game,dir,game->map);
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
