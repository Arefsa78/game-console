#include <graphics.h>
#include "map.h"
#include <stdio.h>
#include "render.h"
#include "rule.h"

Map map;

int gui_get_color(GUI_Settings *gui, char field_cell, Rule *const rule)
{

      // const Rule foo = *rule;
      if (field_cell == rule->solid_block)
            return gui->solid_block;
      if (field_cell == rule->move_block)
            return gui->move_block;
      if (field_cell == rule->death_block)
            return gui->death_block;
      if (field_cell == rule->wall)
            return gui->wall;
      if (field_cell == rule->charecter)
            return gui->charecter;
      if (field_cell == rule->target)
            return gui->target;
      if (field_cell == rule->object)
            return gui->object;
      if (field_cell == rule->attack_range)
            return gui->attack;

      if (field_cell == rule->rpoints.charecter)
            return gui->rpoints;
      if (field_cell == rule->opp.charecter)
            return gui->opp;
      if (field_cell == rule->put.charecter)
            return gui->put;
      return 14;
}
void gui_draw(GUI_Settings *gui, Cell *cell, Rule *rule)
{
      int x = cell->point.x;
      int y = cell->point.y;
      int color = gui_get_color(gui, cell->color, rule);
      setcolor(color);
      // printf("%d", cell->color);
      rectangle(gui->width * y, gui->height * x, gui->width * (y + 1), gui->height * (x + 1));
      floodfill(gui->width * y + 1, gui->height * x + 1, cell->color % 11 + 1);
}

void gui_init(GUI_Settings *gui)
{

      int gd = DETECT;
      int gm;
      initgraph(&gd, &gm, "C:\\TC\\BGI");
}
int main()
{
      test_init(&map, 5, 5);

      // TODO GIVE ME GUI
      GUI_Settings gui;
      gui.width = 40;
      gui.height = 40;
      gui.solid_block = RED;
      // TODO GIVE ME  rule
      Rule rule;
      rule.solid_block = 'C';

      // set GUI
      gui_init(&gui);


      for (int i = 0; i < 5; i++)
      {
            for (int j = 0; j < 5; j++)
            {
                  // printf("%d", map.field[i][j]);
                  Cell foo;
                  foo.color = map.field[i][j];
                  foo.point.x = i;
                  foo.point.y = j;
                  gui_draw(&gui, &foo, &rule);
            }
            printf("\n");
      }
      getch();
      closegraph();
      return 0;
}


// #include <graphics.h>
// #include "map.h"
// #include <stdio.h>
// #include "render.h"
// #include "rule.h"

// int gui_get_color(GUI_Settings *gui, char field_cell, Rule *const rule)
// {

//       fprintf(stdout, "%d", rule->solid_block);
//       // const Rule cell = *rule;
//       if (field_cell == rule->solid_block)
//             return gui->solid_block;
//       if (field_cell == rule->move_block)
//             return gui->move_block;
//       if (field_cell == rule->death_block)
//             return gui->death_block;
//       if (field_cell == rule->wall)
//             return gui->wall;
//       if (field_cell == rule->charecter)
//             return gui->charecter;
//       if (field_cell == rule->target)
//             return gui->target;
//       if (field_cell == rule->object)
//             return gui->object;
//       if (field_cell == rule->attack_range)
//             return gui->attack;

//       if (field_cell == rule->rpoints.charecter)
//             return gui->rpoints;
//       if (field_cell == rule->opp.charecter)
//             return gui->opp;
//       if (field_cell == rule->put.charecter)
//             return gui->put;

//       return BLUE;
// }
// void gui_draw(GUI_Settings *gui, Cell *cell, Rule *rule)
// {
//       int x = cell->point.x;
//       int y = cell->point.y;
//       int color = gui_get_color(gui, cell->color, rule);
//       setcolor(color);
//       // printf("%d", cell->color);
//       rectangle(gui->width * y, gui->height * x, gui->width * (y + 1), gui->height * (x + 1));
//       floodfill(gui->width * y + 1, gui->height * x + 1, cell->color % 11 + 1);
// }

// void gui_clear()
// {
//       setcolor(BLACK);
//       const int inf = 2000;
//       // printf("%d", cell->color);
//       rectangle(0, 0, inf, inf);
//       floodfill(50, 50, BLACK);
// }

// void gui_init_settings(GUI_Settings *gui)
// {
//       gui->width = 40;
//       gui->height = 40;
//       gui->solid_block = RED;
//       gui->death_block = BLACK;
// }
// void gui_init(GUI_Settings *gui)
// {

//       int gd = DETECT;
//       int gm;
//       initgraph(&gd, &gm, "C:\\TC\\BGI");

//       gui_init_settings(gui);
// }

// // main function
// void gui(Map *map, Rule *rule)
// {
//       GUI_Settings gui;
//       gui_init(&gui);

//       for (int i = 0; i < map->height; i++)
//       {
//             for (int j = 0; j < map->width; j++)
//             {
//                   // printf("%d", map.field[i][j]);
//                   Cell cell;
//                   cell.color = map->field[i][j];
//                   cell.point.x = i;
//                   cell.point.y = j;
//                   gui_draw(&gui, &cell, &rule);
//             }
//             // printf("\n");
//       }

//       getch();
//       closegraph();
//       return 0;
// }

// int main()
// {
//       Map map;
//       map.width = 5;
//       map.height = 10;
//       test_init(&map, map.height, map.width);

//       Rule rule;
//       rule.solid_block = 'C';
//       rule.death_block = 'B';

//       // for(int i=0;i<map.height;i++){
//       //       for(int j=0;j<map.width;j++){
//       //             printf("%c",map.field[i][j]);
//       //       }
//       //       printf("\n");
//       // }

//       gui(&map, &rule);
//       return 1;
// }