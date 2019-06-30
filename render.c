#include <graphics.h>
#include "map.h"
#include <stdio.h>
#include "render.h"

Map map;

void draw(Cell *cell)
{
      int x = cell->point.x;
      int y = cell->point.y;

      setcolor((int)cell->color % 11 + 1);
      // printf("%d", cell->color);
      rectangle(WIDTH * y, HEIGHT * x, WIDTH * (y + 1), HEIGHT * (x + 1));
      floodfill(WIDTH * y + 1, HEIGHT * x + 1, cell->color % 11 + 1);
}

int main()
{
      test_init(&map, 5, 5);

      int gd = DETECT;
      int gm;
      initgraph(&gd, &gm, "C:\\TC\\BGI");
      for (int i = 0; i < 5; i++)
      {
            for (int j = 0; j < 5; j++)
            {
                  // printf("%d", map.field[i][j]);
                  Cell foo;
                  foo.color = map.field[i][j];
                  foo.point.x = i;
                  foo.point.y = j;
                  draw(&foo);
            }
            printf("\n");
      }

      getch();
      closegraph();
      return 0;
}