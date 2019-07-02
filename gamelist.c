//
// Created by Aref on 19/07/02.
//

#include <stdio.h>
#include <malloc.h>
#include "gamelist.h"
#include "etc.h"

int show_games(char *directory, Vector *game_list) {
    game_list = pushback(game_list, 0);
    DIR *dir = opendir(directory);
    struct dirent *file;
    if (dir == NULL) {
        printf("directory cant open\n");
        return 0;
    }
    while ((file = readdir(dir)) != NULL) {
        char tmp[20];
        from_to(file->d_name, tmp, 0, find(file->d_name, '-'));
        if (compare(tmp, "map"))
            continue;

        char *game_name = (char *) malloc(sizeof(char) * 20);
        from_to(file->d_name, game_name, find(file->d_name, '-'), find(file->d_name, '.'));
        Vector *new = pushback(game_list, sizeof(char *));
        new->data = game_name;
    }
    closedir(dir);
}

int choose_game(Vector *game_list) {
    printf("***Games***\nid\tgame-name\n");
    int i = 0;
    for(Vector* it = game_list; it != NULL; it = it->next){
        if(it->data == NULL) continue;
        printf("%d\t%s\n", i, (char*)it->data);
    }
    int n;
    printf("Choose a game: ");
    scanf("%d", &n);
    if(n > length_list(game_list)) {
        printf("Wrong choose\n");
        return choose_game(game_list);
    }
    return n;
}
