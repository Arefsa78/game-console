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
            att.flag = 1//atack // att is a AtackAction
            break;
        case key.e:
            ma.control = 'e';//exit
            ma2.control = 'e';

        //tried to make it a 2players game
        case game->rule.up:
            ma2.control = 'l';//left
            break;
        case key.r2:
            ma2.control = 'r';//right
            break;
        case key.u2:
            ma2.control = 'u';//up
            break;
        case key.d2:
            ma2.control = 'd';//down
            break;
        case key.p2:
            ma2.control = 'p';//put
            break;
        case key.a2:
            att2.flag = 1//atack // att is a AtackAction
            break;

    }
}

void puter(struct Put put, int x, int y, char **map) {// prototype baraye function put kardan/
    if (put.lim > 0) {
        map[x][y] == put.block;
        put.lim -= 1;
    }
}

void attack(MoveAction ma,AttackAction att,Object obj, char** map){

    int objx=obj.point.x;
    int objy=obj.point.x;
    int attx=0;
    int atty=0;

    switch(ma.control){

        case 'l':

            attx=objx-att.range;
            if(attx<0)
                attx=0;

            for(;attx<objx;attx++){
                if(map[attx][objy]==DeathBlock.name){
                    map[attx][objy]=' ';
                }
                if(map[attx][objy]==opp.name){
                    map[attx][objy]=' ';
                    end(Character);
                }
                else
                    continue;
            }
            break;

        case 'r':

            attx=objx+att.range;
            if(attx>maxx)//maxx bishtarin x baraye map
                attx=maxx;

            for(;attx>objx;attx--){
                if(map[attx][objy]==DeathBlock.name){
                    map[attx][objy]=' ';
                }
                if(map[attx][objy]==opp.name){
                    map[attx][objy]=' ';
                    end(Character);
                }
                else
                    continue;
            }
            break;

        case 'u':

            atty=objy+att.range;
            if(atty>maxy)
                atty=maxy;

            for(;atty>objy;atty--){
                if(map[objx][atty]==DeathBlock.name){
                    map[objx][atty]=' ';
                }
                if(map[objx][atty]==opp.name){
                    map[objx][atty]=' ';
                    end(Character);
                }
                else
                    continue;
            }
            break;
        case 'd':

            atty=objy-att.range;
            if(atty<0)
                atty=0;

            for(;atty<objy;atty++){
                if(map[objx][atty]==DeathBlock.name){
                    map[objx][atty]=' ';
                }
                if(map[objx][atty]==opp.name){
                    map[objx][atty]=' ';
                    end(Character);
                }
                else
                    continue;
            }
            break;

    }
}

void movefunction(MoveAction ma,MoveAction ma2, AttackAction att,AttackAction att2, Object obj,Object obj2, char **map, struct Put put,struct Put put2) {
    int objx = obj.point.x;
    int objy = obj.point.y;
    int objx2 = obj.point.x;
    int objy2 = obj.point.y;

    //char* objn=obj.charecter;

    //map ro nemidoonam chetor tarif kardi haghighatan :|
    //struct haye block ha ham hamintor...
    //function end age dakhelesh opp bashe harif borde age Character bashe player borde va age game bashe neshoone exit kardan az bazie.

    if(att.flag==1){
        attack(ma,att,obj,map);
        att.flag=0;
    }

    if(att2.flag==1){
        attack(ma,att2,obj2,map);
        att.flag=0;
    }
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

        case 'e':
            end(game);

    switch (ma2.control) {
        case 'l':
            if (map[objx2 - 1][objy2] == ' ') {
                obj2.point.x -= 1;
            }
            if (map[objx2 - 1][objy2] == SolidBlock.name || map[objx2 - 1][objy2] == Wall.name) {
                continue;
            }
            if (map[objx2 - 1][objy2] == MoveBlock.name) {
                obj2.point.x -= 1;
                MoveBlock.point.x -= 1;
            }
            if (map[objx2 - 1][objy2] == DeathBlock.name) {
                end(opp);
            }
            if (map[objx2 - 1][objy2] == OBJ.name) {
                obj.point.x -= 1;
                OBJ.point.x -= 1;
                if (Target.point.x == OBJ.point.x && Target.point.y == OBJ.point.y) {
                    end(Character2);
                }
            }
            break;
        case 'd':
            if (map[objx2][objy2 - 1] == ' ') {
                obj2.point.y -= 1;
            }
            if (map[objx2][objy2 - 1] == SolidBlock.name || map[objx2][objy2 - 1] == Wall.name) {
                continue;
            }
            if (map[objx2][objy2 - 1] == MoveBlock.name) {
                obj2.point.y -= 1;
                MoveBlock.point.y -= 1;
            }
            if (map[objx2][objy2 - 1] == DeathBlock.name) {
                end(opp);
            }
            if (map[objx2][objy2 - 1] == OBJ.name) {
                obj2.point.y -= 1;
                OBJ.point.y -= 1;
                if (Target.point.x == OBJ.point.x && Target.point.y == OBJ.point.y) {
                    end(Character2);
                }
            }
            break;
        case 'u':
            if (map[objx2][objy2 + 1] == ' ') {
                obj2.point.y += 1;
            }
            if (map[objx2][objy2 + 1] == SolidBlock.name || map[objx2][objy2 + 1] == Wall.name) {
                continue;
            }
            if (map[objx2][objy2 + 1] == MoveBlock.name) {
                obj2.point.y += 1;
                MoveBlock.point.y += 1;
            }
            if (map[objx2][objy2 + 1] == DeathBlock.name) {
                end(opp);
            }
            if (map[objx2][objy2 + 1] == OBJ.name) {
                obj2.point.y += 1;
                OBJ.point.y += 1;
                if (Target.point.x == OBJ.point.x && Target.point.y == OBJ.point.y) {
                    end(Character2);
                }
            }
            break;

        case 'r':
            if (map[objx2 + 1][objy2] == ' ') {
                obj2.point.x += 1;
            }
            if (map[objx2 + 1][objy2] == SolidBlock.name || map[objx2 + 1][objy2] == Wall.name) {
                continue;
            }
            if (map[objx2 + 1][objy2] == MoveBlock.name) {
                obj2.point.x += 1;
                MoveBlock.point.x += 1;
            }
            if (map[objx2 + 1][objy2] == DeathBlock.name) {
                end(opp);
            }
            if (map[objx2 + 1][objy2] == OBJ.name) {
                obj2.point.x += 1;
                OBJ.point.x += 1;
                if (Target.point.x == OBJ.point.x && Target.point.y == OBJ.point.y) {
                    end(Character2);
                }
            }
            break;

        case 'p':
            puter(put2, objx2, objy2, map);

        case 'e':
            end(game);

    }
}
