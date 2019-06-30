#define WIDTH 40
#define HEIGHT 40

// #include "object.h"

typedef struct Cell Cell;
typedef struct Point Point;

struct Point{
    int x,y;
}
struct Cell
{
    Point point;
    char color;
};