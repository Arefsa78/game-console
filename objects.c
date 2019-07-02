//
// Created by Aref on 19/06/30.
//

#include "objects.h"
#include "rule.h"
#include "game.h"
#include "etc.h"

void init_move(MoveAction *move, Point point, char r) {
    move->move = point;
    move->control = r;
}

void move_object(Object *obj, Game *game) {
    Rule *rule = game->rule;
    Map *map = game->map;
    Point new_pos = plus_point(obj->point, obj->move_dir.move);
    if (can_go(rule, (char) cell(map, new_pos))) {
        obj->point = new_pos;
    }
    if (die(rule, (char) cell(map, new_pos)))
        obj->point = INVALID_POINT; //DEAD :)
    if (obj->charecter == (char) game->rule->charecter ||
            obj->charecter == (char) game->rule->opp.charecter)
        move_another(obj, game);
}

void move_another(Object *obj, Game *game) {
    Map *map = game->map;
    Rule *rule = game->rule;
    if (cell(map, obj->point) == rule->object) {
        game->object.move_dir = obj->move_dir;
        move_object(&game->object, game);
        return;
    }
    for (Vector *it = game->move_blocks; it != NULL; it = it->next) {
        if (it->data == NULL) continue;
        Object *block_obj = (Object *) it->data;
        if (same_point(block_obj->point, obj->point)) {
            block_obj->move_dir = obj->move_dir;
            move_object(block_obj, game);
            return;
        }
    }
}

Point plus_point(Point a, Point b) {
    return (Point) {a.x + b.x, a.y + b.y};
}

int same_point(Point a, Point b) {
    return a.x == b.x && a.y == b.y;
}

//////////////////////////////////////////////////////////////////////
int isSafe(int map[][], int visited[][], int x, int y) { // map / vis ro ok konesh
    if (map[x][y] == 0 || visited[x][y]) return 0;
    return 1;
}

int isValid(int x, int y, Game *game) {
    if (x < game->map->width && y < game->map->height && x >= 0 && y >= 0) return 1;
    return 0;
}

void BFS(int map[][], int visited[][], int i, int j, int x, int y, int* min_dist , int dist ,char* path ,char* dir,Game *game) { // Dir va min_dist bayad por beshan inja
    if (i == x && j == y) {
        if(dist < *min_dist){
            *min_dist = dist;
            *dir = path[0];
        }
        *min_dist = (dist > *min_dist) ? *min_dist : dist;
        return;
    }
    visited[i][j] = 1;

    if (isValid(i - 1, j , game) && isSafe(map, visited, i - 1, j)){ // up
        path[dist] = 'U';
        BFS(map, visited, i - 1, j, x, y, min_dist, dist + 1 , dir , game);
    }
    if (isValid(i + 1, j , game) && isSafe(map, visited, i + 1, j)) { // Down
        path[dist] = 'D';
        BFS(map, visited, i + 1, j, x, y, &min_dist, dist + 1 , dir , game);

    }
    if (isValid(i, j + 1 , game) && isSafe(map, visited, i, j + 1)){ // right
        path[dist] = 'R';
        BFS(map, visited, i, j + 1, x, y, &min_dist, dist + 1 , dir , game);
    }


    if (isValid(i, j - 1 , game) && isSafe(map, visited, i, j - 1)){  // left
        path[dist] = 'L';
        BFS(map, visited, i, j - 1, x, y, &min_dist, dist + 1 , dir , game);
    }

    visited[i][j] = 0;
}

void choose_dir(Object *opp, Point target, Game *game) {
    const int X = game->map->width , Y = game->map->height;
    int mapMats[X][Y] = {0}, Visited = {0} , min_dist = X*Y; // set map
    char path[X*Y] = "", dir = 'N';
    Vector *tmpWall = game->solidBlocks; // tmp wall for every block and wall and death ones
    for (Vector *it = tmpWall; it != NULL; it = it->next) { // a simple fucking for
        Object *block_obj = (Object *) it->data;
        mapMats[block_obj->point.x][block_obj->point.y] = '1'
    }
    tmpWall = game->deathBlocks;
    for (Vector *it = tmpWall; it != NULL; it = it->next) { // a simple fucking for
        Object *block_obj = (Object *) it->data;
        mapMats[block_obj->point.x][block_obj->point.y] = '1'
    }
    tmpWall = game->raindbs;
    for (Vector *it = tmpWall; it != NULL; it = it->next) { // a simple fucking for
        Object *block_obj = (Object *) it->data;
        mapMats[block_obj->point.x][block_obj->point.y] = '1'
    }
    tmpWall = game->walls;
    for (Vector *it = tmpWall; it != NULL; it = it->next) { // a simple fucking for
        Object *block_obj = (Object *) it->data;
        mapMats[block_obj->point.x][block_obj->point.y] = '1'
    }
    tmpWall = game->move_blocks;
    for (Vector *it = tmpWall; it != NULL; it = it->next) { // a simple fucking for
        Object *block_obj = (Object *) it->data;
        mapMats[block_obj->point.x][block_obj->point.y] = '1'
    }
    BFS(mapMats,Visited,opp->point.x,opp->point.y,target.x,target.y,&min_dist,0,path,&dir,game);
    opp->move_dir.move = opp->point;
    if(dir == 'U')
        opp->move_dir.move.y++;
    else if(dir == 'D')
        opp->move_dir.move.y--;
    else if(dir == 'R')
        opp->move_dir.move.x++;
    else if(dir == 'L')
        opp->move_dir.move.x--;
    else opp->move_dir.move = INVALID_POINT;
}

void display_point(Point p) {
    printf("(%d, %d\n)", p.x, p.y);
}
