//
// Created by Aref on 19/06/30.
//

#include <malloc.h>
#include <string.h>
#include "game.h"
#include "etc.h"

void init_game(Game *game, char *game_name) {
    game->rule = (Rule *) malloc(sizeof(Rule) * 1);
    game->map = (Map *) malloc(sizeof(Map) * 1);

    char x[40] = LOCAL_DIR"game-\0";
    char y[40] = LOCAL_DIR"map-\0";

    FILE *rules_file = fopen(strcat(x, game_name), "r");
    FILE *map_file = fopen(strcat(y, game_name), "r");

    game->solidBlocks = NULL;
    game->deathBlocks = NULL;
    game->raindbs = NULL;
    game->move_blocks = NULL;
    game->walls = NULL;
    game->rpoints = NULL;
    game->opps = NULL;
    game->solidBlocks = pushback(game->solidBlocks, 0);
    game->deathBlocks = pushback(game->deathBlocks, 0);
    game->raindbs = pushback(game->raindbs, 0);
    game->move_blocks = pushback(game->move_blocks, 0);
    game->walls = pushback(game->walls, 0);
    game->rpoints = pushback(game->rpoints, 0);
    game->opps = pushback(game->opps, 0);
    init_rule2(game->rule);

    init_rule(rules_file, game->rule);
    init_map(map_file, game->map);

    init_game_with_map(game);

    game->time.frame_length = 500;
    game->time.game_length = 50000;

    game->score = 0;
    game->attack = 0;
    game->game_over = 0;
}

Point get_dir(char point, Map *map) {
    int y1 = 0;
    int x1 = 0;
    int y2 = map->height;
    int x2 = map->width;
    Point dir;

    for (; x1 <= x2; x1++) {
        for (; y1 <= y2; y1++) {
            if (map->field[x1][y1] == point) {
                dir.x = x1 - 1;
                dir.y = y1 - 1;
            }
        }
    }

    return dir;
}

void best_move(Game *game, Object *opp, Point dir, Map *map) {
    if (opp->point.x >= dir.x && !is_obj_opp(game->rule, (char) cell(map, plus_point(opp->point, (Point) {-1, 0}))))
        opp->move_dir.move = (Point) {-1, 0};
    else if (opp->point.x < dir.x && !is_obj_opp(game->rule, (char) cell(map, plus_point(opp->point, (Point) {+1, 0}))))
        opp->move_dir.move = (Point) {+1, 0};
    else if (opp->point.y >= dir.y &&
             !is_obj_opp(game->rule, (char) cell(map, plus_point(opp->point, (Point) {0, -1}))))
        opp->move_dir.move = (Point) {0, -1};
    else if (opp->point.y < dir.y && !is_obj_opp(game->rule, (char) cell(map, plus_point(opp->point, (Point) {0, +1}))))
        opp->move_dir.move = (Point) {0, +1};
}

void opps_decision(Game *game, Object *opp) {
    Point dir = find_nearest(game->map, opp->point, (char) game->rule->opp.target);
    best_move(game, opp, dir, game->map);
}

void next_frame(Game *game) {
    db(-10);
    player_attack(game);
    db(-9);
    opps_move(game);
    move_object(&game->player, game);
    if (same_point(game->player.point, INVALID_POINT))
        game->game_over = 1;
    db(0);
    raindbs_move(game);
    db(1);
    make_raindb(game);
    db(2);
    change_map(game);
    db(3);
    check_game_over_end(game);
    db(4);
    clean_nulls(game);
    db(5);
}

void opps_move(Game *game) {
    Vector *opps = game->opps;
    for (Vector *it = opps; it != NULL; it = it->next) {
        if (it->data == NULL) continue;
        Object *opp = (Object *) it->data;
        if (same_point(opp->point, INVALID_POINT)) continue;
        opps_decision(game, opp);
        move_object(opp, game);
    }
}

void init_game_with_map(Game *game) {
    set_rpoints(game);
    Map *map = game->map;
    Rule *rule = game->rule;
    for (int y = 0; y < map->height; y++) {
        for (int x = 0; x < map->width; x++) {
            char ob = (char) map->field[y][x];
            Object *new_obj = (Object *) malloc(sizeof(Object));
            new_obj->point = (Point) {x, y};
            new_obj->charecter = ob;
            if (ob == (char) rule->solid_block) {
                Vector *new = pushback(game->solidBlocks, sizeof(Object));
                new->data = new_obj;
            } else if (ob == (char) rule->death_block) {
                Vector *new = pushback(game->deathBlocks, sizeof(Object));
                new->data = new_obj;
            } else if (ob == (char) rule->move_block) {
                Vector *new = pushback(game->move_blocks, sizeof(Object));
                new->data = new_obj;
            } else if (ob == (char) rule->wall) {
                Vector *new = pushback(game->walls, sizeof(Object));
                new->data = new_obj;
            } else if (ob == (char) rule->rpoints.charecter) {
                Vector *new = pushback(game->rpoints, sizeof(Object));
                new->data = new_obj;
            } else if (ob == (char) rule->opp.charecter) {
                Vector *new = pushback(game->opps, sizeof(Object));
                new->data = new_obj;
            } else if (ob == (char) rule->charecter) {
                game->player = *new_obj;
                free(new_obj);
            } else if (ob == (char) rule->object) {
                game->object = *new_obj;
                free(new_obj);
            } else if (ob == (char) rule->target) {
                game->target = *new_obj;
                free(new_obj);
            }
        }
    }
}

void raindbs_move(Game *game) {
    Vector *raindbs = game->raindbs;
    for (Vector *it = raindbs; it != NULL; it = it->next) {
        if (it->data == NULL) continue;
        Object *raindb = (Object *) it->data;
        if (same_point(raindb->point, INVALID_POINT)) continue;
        move_object(raindb, game);
        if (cell(game->map, raindb->point) == (char) game->rule->charecter)
            game->game_over = 1;
        if (is_obj(game->rule, (char) cell(game->map, raindb->point)))
            raindb->point = INVALID_POINT;
    }
}

void make_raindb(Game *game) {
    for (int i = 0; i < game->rule->raindb; i++) {
        Object *new_db = (Object *) malloc(sizeof(Object));
        new_db->charecter = (char) game->rule->death_block;
        new_db->move_dir.move = (Point) {0, 1};
        new_db->point = (Point) {rand() % game->map->width, 0};
        pushback(game->raindbs, sizeof(Object))->data = new_db;
    }
}

void change_map(Game *game) {
    Map *map = game->map;
    for (int y = 0; y < map->height; y++)
        for (int x = 0; x < map->width; x++)
            map->field[y][x] = ' ';

    db(mo2);
    set_vector_on_map(game->solidBlocks, game->map);
    db(mo3);
    set_vector_on_map(game->deathBlocks, game->map);
    db(mo4);
    set_vector_on_map(game->raindbs, game->map);
    db(mo5);
    set_vector_on_map(game->move_blocks, game->map);
    db(mo6);
    set_vector_on_map(game->walls, game->map);
    db(mo7);
    set_vector_on_map(game->rpoints, game->map);
    db(mo8);
    set_vector_on_map(game->opps, game->map);
    db(mo9);
    set_obj_on_map(&game->player, game->map);
    db(mo10);
    set_obj_on_map(&game->target, game->map);
    db(mo11);
    set_obj_on_map(&game->object, game->map);
    db(mo12);
}

void set_vector_on_map(Vector *objs, Map *map) {
    for (Vector *it = objs; it != NULL; it = it->next) {
        if (it->data == NULL) continue;
        Object *obj = (Object *) it->data;
        if (same_point(obj->point, INVALID_POINT)) continue;
        map->field[obj->point.y][obj->point.x] = obj->charecter;
    }
}

void set_obj_on_map(Object *objs, Map *map) {
    if (is_in_area(map, objs->point))
        map->field[objs->point.y][objs->point.x] = objs->charecter;
}

void end_game(Game *game) {
    free(game->rule);
    for (int i = 0; i < game->map->height; i++)
        free(game->map->field[i]);
    free(game->map->field);
    free(game->map);

    free_vector(game->solidBlocks);
    free_vector(game->deathBlocks);
    free_vector(game->raindbs);
    free_vector(game->move_blocks);
    free_vector(game->walls);
    free_vector(game->rpoints);
    free_vector(game->opps);
    free(game);
}

void drop(Game *game) {
    Rule *rule = game->rule;
    if (rule->put.number <= 0)
        return;
    char ob = (char) rule->put.charecter;
    Object *new_obj = (Object *) malloc(sizeof(Object));
    new_obj->point = game->player.point;
    new_obj->charecter = ob;
    if (ob == (char) rule->solid_block) {
        Vector *new = pushback(game->solidBlocks, sizeof(Object));
        new->data = new_obj;
    } else if (ob == (char) rule->death_block) {
        Vector *new = pushback(game->deathBlocks, sizeof(Object));
        new->data = new_obj;
    } else if (ob == (char) rule->move_block) {
        Vector *new = pushback(game->move_blocks, sizeof(Object));
        new->data = new_obj;
    } else if (ob == (char) rule->wall) {
        Vector *new = pushback(game->walls, sizeof(Object));
        new->data = new_obj;
    }
}

void set_rpoints(Game *game) {
    int n = 0;
    while (n < game->rule->rpoints.number) {
        Object *new_obj = (Object *) malloc(sizeof(Object));
        random_point(game->map, game->rule, new_obj);
        new_obj->charecter = (char) game->rule->rpoints.charecter;
        Vector *new = pushback(game->rpoints, sizeof(Object));
        new->data = new_obj;
        n += 1;
    }
}

void check_game_over_end(Game *game) {
    if (cell(game->map, game->player.point) == (char) game->rule->death_block) {
        game->game_over = 1;
        return;
    }
    for (Vector *it = game->raindbs; it != NULL; it = it->next) {
        if (it->data == NULL) continue;
        Object *obj = (Object *) it->data;
        if (same_point(obj->point, INVALID_POINT)) continue;
        if (same_point(obj->point, game->player.point)) {
            game->game_over = 1;
            return;
        }
    }
    for (Vector *it = game->opps; it != NULL; it = it->next) {
        if (it->data == NULL) continue;
        Object *obj = (Object *) it->data;
        if (same_point(obj->point, INVALID_POINT)) continue;
        if (same_point(obj->point, game->player.point)) {
            game->game_over = 1;
            return;
        }
    }
}

void clean_nulls(Game *game) {
    clean_vector(game->solidBlocks);
    clean_vector(game->deathBlocks);
    clean_vector(game->raindbs);
    clean_vector(game->move_blocks);
    clean_vector(game->walls);
    clean_vector(game->rpoints);
    clean_vector(game->opps);
}

void player_attack(Game *game) {
    Point tar = game->player.point;
    if (game->attack == 0)
        return;
    if (same_point(game->player.move_dir.move, (Point) {0, 0}))
        return;
    for (int i = 0; i < game->rule->attack_range; i++) {
        tar = plus_point(tar, game->player.move_dir.move);
        if (!is_in_area(game->map, tar))
            continue;
        if (!is_obj(game->rule, cell(game->map, tar)))
            continue;
        Object *opp = find_by_point(game->opps, tar);
        if (opp == NULL)
            continue;
        opp->point = INVALID_POINT;
    }
}
