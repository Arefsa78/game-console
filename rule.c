//
// Created by Aref on 19/06/29.
//

#include "rule.h"
#include "etc.h"

int set_rules(FILE *file, Rule *rule) {
    char line[50];
    while(get_line(file, line)){

    }
}

int parser(char *line, Rule *rule) {
    int i = find(line, '=');
    if (i == NOT_FOUND)
        return 0;
    char left[20];
    from_to(line, left, 0, i);
    //and now ifs beginssss :)
}