#include <graphics.h>
#include "map.h"
#include <stdio.h>


Map map;

int main()
{
      map.width = map.height = 5;
      return 0;
      for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                  int foo = rand()%11;
                  map.field[i][j] = foo;
                  printf("%c",map.field[i][j]);
            }
            printf("\n");
      }

      return 0;
}