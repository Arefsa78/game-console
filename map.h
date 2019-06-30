//
// Created by Aref on 19/06/30.
//

#ifndef GAME_CONSOLE_MAP_H
#define GAME_CONSOLE_MAP_H

typedef struct Map Map; 

struct Map{
    int width;
    int height;
    int** field;
};

#endif //GAME_CONSOLE_MAP_H
