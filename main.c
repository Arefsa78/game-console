//
// Created by Aref on 19/06/29.
//
#include <stdio.h>
#include "game.h"

int main() {
    char x[20], y[20];
    scanf("%s %s", x, y);
    printf("x: %s\ny: %s\n*******\n", x, y);
    char* r = strcat(x, y);
    printf("x: %s\ny: %s\nr: %s", x, y, r);
}