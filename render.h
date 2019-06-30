#define WIDTH 40
#define HEIGHT 40

#include "objects.h"

typedef struct Cell Cell;
typedef struct Point Point;

struct Cell
{
    Point point;
    char color;
};