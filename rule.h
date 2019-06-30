//
// Created by Aref on 19/06/29.
//

#include <stdio.h>

#ifndef GAME_CONSOLE_RULE_H
#define GAME_CONSOLE_RULE_H

#define NOT_DEFINE -405

typedef struct Rule Rule;
typedef struct Point_R Point_R;
typedef struct Opp_R Opp_R;
typedef struct Put_R Put_R;

struct Point_R{
    int charecter;
    int point;
    int number;
};

struct Opp_R{
    int charecter;
    int target;
};

struct Put_R{
    int charecter;
    int control;
    int number;
};

struct Rule{
    int solid_block;
    int death_block;
    int move_block;
    int wall;

    int charecter;
    int target;
    int object;

    int up, down, left, right;
    int exit;
    int time;
    int attack_range;

    Point_R rpoints;
    Opp_R opp;
    Put_R put;
};

int set_rules(FILE* file, Rule* rule);
int parser(char* line, Rule* rule);
void init_rule(Rule* rule);

#endif //GAME_CONSOLE_RULE_H
