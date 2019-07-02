//
// Created by Aref on 19/07/02.
//

#include <stdio.h>
#include <malloc.h>
#include <mem.h>
#include "gamelist.h"
#include "etc.h"

int get_games(char *directory, Vector *game_list) {
    DIR *dir = opendir(directory);
    struct dirent *file;
    if (dir == NULL) {
        printf("directory cant open\n");
        return 0;
    }
    while ((file = readdir(dir)) != NULL) {
        if(file->d_name[0] == '.') continue;
        char tmp[20];
        from_to(file->d_name, tmp, 0, find(file->d_name, '-'));
        if (compare(tmp, "map"))
            continue;

        char *game_name = (char *) malloc(sizeof(char) * 20);
        from_to(file->d_name, game_name, find(file->d_name, '-')+1, find(file->d_name, '.'));
        pushback(game_list, sizeof(char *))->data = strcat(game_name, ".txt\0");
    }
    closedir(dir);
    return 1;
}

int choose_game(Vector *game_list) {
    printf("***Games***\nid\tgame-name\n");
    int i = 0;
    for(Vector* it = game_list; it != NULL; it = it->next){
        if(it->data == NULL) continue;
        printf("%d\t%s\n", i, (char*)it->data);
    }
    int n;
    printf("Choose a game: 0\n");
    n = 0;//scanf("%d", &n);
    if(n > length_list(game_list)) {
        printf("Wrong choose\n");
        return choose_game(game_list);
    }
    return n;
}
