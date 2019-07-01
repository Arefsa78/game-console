#include "move.h"

void getkey(Game *game) {

    char c;
    if (kbhit())
        c = getch();
    else
        return;

    switch (c) {
        case game->rule.up:
            ma.control = 'l';//left
            break;
        case key.r:
            ma.control = 'r';//right
            break;
        case key.u:
            ma.control = 'u';//up
            break;
        case key.d:
            ma.control = 'd';//down
            break;
        case key.p:
            ma.control = 'p';//put
            break;
        case key.a:
            ma.control = 'a';//atack
            break;
        case key.e:
            ma.control = 'e';//exit

    }
}

void puter(struct Put put, int x, int y, char **map) {// prototype baraye function put kardan/
    if (put.lim > 0) {
        map[x][y] == put.block;
        put.lim -= 1;
    }
}

void movefunction(MoveAction ma, Object obj, char **map, struct Put put) {
    int objx = obj.point.x;
    int objy = obj.point.y;
    //char* objn=obj.charecter;

    //map ro nemidoonam chetor tarif kardi haghighatan :|
    //struct haye block ha ham hamintor...
    //function end age dakhelesh opp bashe harif borde age Character bashe player borde va age game bashe neshoone exit kardan az bazie.

    switch (ma.control) {
        case 'l':
            if (map[objx - 1][objy] == ' ') {
                obj.point.x -= 1;
            }
            if (map[objx - 1][objy] == SolidBlock.name || map[objx - 1][objy] == Wall.name) {
                continue;
            }
            if (map[objx - 1][objy] == MoveBlock.name) {
                obj.point.x -= 1;
                MoveBlock.point.x -= 1;
            }
            if (map[objx - 1][objy] == DeathBlock.name) {
                end(opp);
            }
            if (map[objx - 1][objy] == OBJ.name) {
                obj.point.x -= 1;
                OBJ.point.x -= 1;
                if (Target.point.x == OBJ.point.x && Target.point.y == OBJ.point.y) {
                    end(Character);
                }
            }
            break;
        case 'd':
            if (map[objx][objy - 1] == ' ') {
                obj.point.y -= 1;
            }
            if (map[objx][objy - 1] == SolidBlock.name || map[objx][objy - 1] == Wall.name) {
                continue;
            }
            if (map[objx][objy - 1] == MoveBlock.name) {
                obj.point.y -= 1;
                MoveBlock.point.y -= 1;
            }
            if (map[objx][objy - 1] == DeathBlock.name) {
                end(opp);
            }
            if (map[objx][objy - 1] == OBJ.name) {
                obj.point.y -= 1;
                OBJ.point.y -= 1;
                if (Target.point.x == OBJ.point.x && Target.point.y == OBJ.point.y) {
                    end(Character);
                }
            }
            break;
        case 'u':
            if (map[objx][objy + 1] == ' ') {
                obj.point.y += 1;
            }
            if (map[objx][objy + 1] == SolidBlock.name || map[objx][objy + 1] == Wall.name) {
                continue;
            }
            if (map[objx][objy + 1] == MoveBlock.name) {
                obj.point.y += 1;
                MoveBlock.point.y += 1;
            }
            if (map[objx][objy + 1] == DeathBlock.name) {
                end(opp);
            }
            if (map[objx][objy + 1] == OBJ.name) {
                obj.point.y += 1;
                OBJ.point.y += 1;
                if (Target.point.x == OBJ.point.x && Target.point.y == OBJ.point.y) {
                    end(Character);
                }
            }
            break;

        case 'r':
            if (map[objx + 1][objy] == ' ') {
                obj.point.x += 1;
            }
            if (map[objx + 1][objy] == SolidBlock.name || map[objx + 1][objy] == Wall.name) {
                continue;
            }
            if (map[objx + 1][objy] == MoveBlock.name) {
                obj.point.x += 1;
                MoveBlock.point.x += 1;
            }
            if (map[objx + 1][objy] == DeathBlock.name) {
                end(opp);
            }
            if (map[objx + 1][objy] == OBJ.name) {
                obj.point.x += 1;
                OBJ.point.x += 1;
                if (Target.point.x == OBJ.point.x && Target.point.y == OBJ.point.y) {
                    end(Character);
                }
            }
            break;

        case 'p':
            puter(put, objx, objy, map);

        case 'a':
            //atack();
        case 'e':
            end(game);

    }
}
