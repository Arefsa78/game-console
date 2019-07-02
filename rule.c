//
// Created by Aref on 19/06/29.
//

#include "rule.h"
#include "etc.h"

int init_rule(FILE *file, Rule *rule) {
    char line[50];
    while (get_line(file, line))
        parser(line, rule);
    return 1;
}

int parser(char *line, Rule *rule) {
    int i = find(line, '=');
    if (i == NOT_FOUND)
        return 0;
    char left[20];
    from_to(line, left, 0, i);
    //and now ifs beginssss :)
    if (compare(left, "solidblock"))
        sscanf(line, "solidblock=%c", &(rule->solid_block));
    else if (compare(left, "deathblock"))
        sscanf(line, "deathblock=%c", &(rule->death_block));
    else if (compare(left, "raindb"))
        sscanf(line, "raindb=%d", &(rule->raindb));
    else if (compare(left, "moveblock"))
        sscanf(line, "moveblock=%c", &(rule->move_block));
    else if (compare(left, "wall"))
        sscanf(line, "wall=%c", &(rule->wall));
    else if (compare(left, "charecter"))
        sscanf(line, "charecter=%c", &(rule->charecter));
    else if (compare(left, "target"))
        sscanf(line, "target=%c", &(rule->target));
    else if (compare(left, "object"))
        sscanf(line, "object=%c", &(rule->object));
    else if (compare(left, "left"))
        sscanf(line, "left=%c", &(rule->left));
    else if (compare(left, "right"))
        sscanf(line, "right=%c", &(rule->right));
    else if (compare(left, "up"))
        sscanf(line, "up=%c", &(rule->up));
    else if (compare(left, "down"))
        sscanf(line, "down=%c", &(rule->down));
    else if (compare(left, "exit"))
        sscanf(line, "exit=%c", &(rule->exit));
    else if (compare(left, "time"))
        sscanf(line, "time=%d", &(rule->time));
    else if (compare(left, "attack"))
        sscanf(line, "attack=%d", &(rule->attack_range));
    else if (compare(left, "rpoint"))
        sscanf(line, "rpoint=%c,%d,%d", &(rule->rpoints.charecter), &(rule->rpoints.point), &(rule->rpoints.number));
    else if (compare(left, "opp"))
        sscanf(line, "opp=%c, %c", &(rule->opp.charecter), &(rule->opp.target));
    else if (compare(left, "put"))
        sscanf(line, "put=%c,%c,%d", &(rule->put.control), &(rule->put.charecter), &(rule->put.number));
}

void init_rule2(Rule *rule) {
    rule->solid_block = NOT_DEFINE;
    rule->death_block = NOT_DEFINE;
    rule->raindb = NOT_DEFINE;
    rule->move_block = NOT_DEFINE;
    rule->wall = NOT_DEFINE;
    rule->charecter = NOT_DEFINE;
    rule->target = NOT_DEFINE;
    rule->object = NOT_DEFINE;
    rule->up = NOT_DEFINE;
    rule->down = NOT_DEFINE;
    rule->right = NOT_DEFINE;
    rule->left = NOT_DEFINE;
    rule->exit = NOT_DEFINE;
    rule->time = NOT_DEFINE;
    rule->attack_range = NOT_DEFINE;
    rule->rpoints = (Point_R) {NOT_DEFINE, NOT_DEFINE, NOT_DEFINE};
    rule->opp = (Opp_R) {NOT_DEFINE, NOT_DEFINE};
    rule->put = (Put_R) {NOT_DEFINE, NOT_DEFINE, NOT_DEFINE};
}

int can_go(Rule *rule, char c) {
    if (c == rule->solid_block)
        return 0;
    if(c == rule->wall)
        return 0;
    return 1;
}

int die(Rule *rule, char c) {
    if(c == rule->death_block)
        return 1;
    return 0;
}
