//
// Created by Aref on 19/06/29.
//
#include <stdio.h>
#include "vector.h"

int main() {
    Vector *foo = NULL;
    foo = pushback(foo, sizeof(int));
    *(int*)index(foo, 0, sizeof(int))->data = 5;
    printf("%d", *(int*)(index(foo, 0, sizeof(int))->data));
    return 0;
}
