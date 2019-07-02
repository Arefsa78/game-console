//
// Created by Aref on 19/06/29.
//
#include <stdio.h>
#include <malloc.h>
//#include "game.h"
#include "vector.h"

int main() {
//    Game *game = (Game *) malloc(sizeof(Game));
//    init_game(game, game_name); //input
//    run_game(game);
//    ini
    Vector* head = NULL;
    for(int i = 0; i < 5; i++) {
        head = pushback(head, sizeof(int));
        printf("i: %d\n", i);
        *(int*)index(head, i, sizeof(int)) = i*2;
    }
    int i = 0;
    for(Vector* it = head; it != NULL; it = it->next)
        printf("head[%d]: %d\n", i++, *(int*)it->data);
}