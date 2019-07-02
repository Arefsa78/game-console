//
// Created by Aref on 19/06/29.
//

#include <stdio.h>
#include "rule.h"

#ifndef GAME_CONSOLE_ETC_H
#define GAME_CONSOLE_ETC_H

#define NOT_FOUND -404
#define LOCAL_DIR "F:\\Aref\\P\\c++\\game-console\\Games\\"
#define db(x) printf(#x"\n")

int get_line(FILE* file,char* line);
int find(char* line, char x);
void from_to(char* old, char* new, int start, int end);
int compare(char* left, char* right);

#endif //GAME_CONSOLE_ETC_H
