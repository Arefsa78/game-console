
#include "objects.h"

typedef struct Cell Cell;
typedef struct GUI_Settings GUI_Settings;

struct Cell
{
    Point point;
    char color;
};

struct GUI_Settings{
    int height ,width;
    // Colors


    int solid_block;//
    int death_block;//
    int move_block;//
    int wall;//

    int charecter;//
    int target;//
    int object;//

    int attack;//

    int rpoints;//
    int opp;//
    int put;//

};