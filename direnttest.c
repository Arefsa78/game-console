#include <dirent.h>
#include <Stdio.h>

#include <stdio.h>
#include <dirent.h>

int main()
{
    DIR *folder;
    struct dirent *entry;
    int files = 0;
    char **list;

    folder = opendir(".");
    if(folder == NULL)
    {
        perror("No games available!");
        return 1;
    }

    while( (entry=readdir(folder)) )
    {
        files++;

        printf("File %3d: %s\n",files,entry->d_name);
    }

    closedir(folder);

    return 0;
}
