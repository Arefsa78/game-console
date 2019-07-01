#include "objects.c"

void getkey(MoveAction ma,AttackAction att){

    char c;
    if (kbhit()) {
        c = getch();

        //key.folan vase ine ke oon chizi ke az file be onvane masalan dokmeye raftan be rast hast taein beshe coon nemidoonam chetor dari file ro mikhoni


        switch (c) {
            case key.l:
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
                att.flag = 1;//atack
                break;
            case key.e:
                 = 'e';//exit

        }
    }
}

void puter(struct Put put, int x,int y,char** map){// prototype baraye function put kardan/
    if(put.lim>0){
        map[x][y]==put.block;
        put.lim-=1;
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

void movefunction(MoveAction ma,AttackAction att, Object obj,char** map, struct Put put){
    int objx=obj.point.x;
    int objy=obj.point.y;
    //char* objn=obj.charecter;

    //map ro nemidoonam chetor tarif kardi haghighatan :|
    //struct haye block ha ham hamintor...
    //function end age dakhelesh opp bashe harif borde age Character bashe player borde va age game bashe neshoone exit kardan az bazie.

    if(att.flag == 1){
        attack(ma,att,obj,char** map);
        att.flag = 0;
    }

    switch(ma.control){
        case 'l':
            if(map[objx-1][objy]==' '){
                obj.point.x-=1;
            }
            if(map[objx-1][objy]==SolidBlock.name || map[objx-1][objy]==Wall.name){
                continue;
            }
            if(map[objx-1][objy]==MoveBlock.name){
                obj.point.x-=1;
                MoveBlock.point.x-=1;
            }
            if(map[objx-1][objy]==DeathBlock.name){
                end(opp);
            }
            if(map[objx-1][objy]==OBJ.name){
                obj.point.x-=1;
                OBJ.point.x-=1;
                if(Target.point.x==OBJ.point.x && Target.point.y==OBJ.point.y){
                    end(Character);
                }
            }
            break;
        case 'd':
            if(map[objx][objy-1]==' '){
                obj.point.y-=1;
            }
            if(map[objx][objy-1]==SolidBlock.name || map[objx][objy-1]==Wall.name){
                continue;
            }
            if(map[objx][objy-1]==MoveBlock.name){
                obj.point.y-=1;
                MoveBlock.point.y-=1;
            }
            if(map[objx][objy-1]==DeathBlock.name){
                end(opp);
            }
            if(map[objx][objy-1]==OBJ.name){
                obj.point.y-=1;
                OBJ.point.y-=1;
                if(Target.point.x==OBJ.point.x && Target.point.y==OBJ.point.y){
                    end(Character);
                }
            }
            break;
        case 'u':
            if(map[objx][objy+1]==' '){
                obj.point.y+=1;
            }
            if(map[objx][objy+1]==SolidBlock.name || map[objx][objy+1]==Wall.name){
                continue;
            }
            if(map[objx][objy+1]==MoveBlock.name){
                obj.point.y+=1;
                MoveBlock.point.y+=1;
            }
            if(map[objx][objy+1]==DeathBlock.name){
                end(opp);
            }
            if(map[objx][objy+1]==OBJ.name){
                obj.point.y+=1;
                OBJ.point.y+=1;
                if(Target.point.x==OBJ.point.x && Target.point.y==OBJ.point.y){
                    end(Character);
                }
            }
            break;

        case 'r':
            if(map[objx+1][objy]==' '){
                obj.point.x+=1;
            }
            if(map[objx+1][objy]==SolidBlock.name || map[objx+1][objy]==Wall.name){
                continue;
            }
            if(map[objx+1][objy]==MoveBlock.name){
                obj.point.x+=1;
                MoveBlock.point.x+=1;
            }
            if(map[objx+1][objy]==DeathBlock.name){
                end(opp);
            }
            if(map[objx+1][objy]==OBJ.name){
                obj.point.x+=1;
                OBJ.point.x+=1;
                if(Target.point.x==OBJ.point.x && Target.point.y==OBJ.point.y){
                    end(Character);
                }
            }
            break;

        case 'p':
            puter(put,objx,objy,map);

        case 'e':
            end(game);

    }
}
