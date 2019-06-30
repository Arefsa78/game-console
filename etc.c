//
// Created by Aref on 19/06/29.
//

#include "etc.h"

int get_line(FILE *file, char *line) {
    int c;
    while ((c = fgetc(file)) != EOF) {
        if (c == '\n') {
            *line = 0;
            return 1;
        }
        *(line++) = (char) c;
    }
    return 0;
}

int find(char *line, char x) {
    for (int i = 0; line[i] != 0; i++)
        if (line[i] == x)
            return i;
    return NOT_FOUND;
}

void from_to(char *old, char *new, int start, int end) {
    for (int i = 0; i < end - start; i++)
        new[i] = old[i + start];
    new[end-start] = 0;
}

int compare(char *left, char *right) {
    for (int i = 0; left[i] != 0 && right[i] != 0; i++)
        if (left[i] != right[i])
            return 0;
    return 1;
}
