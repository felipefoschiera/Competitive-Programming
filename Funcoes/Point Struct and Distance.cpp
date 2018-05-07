#include <math.h> // hypot

struct pt{
    int x, y;
    pt(int _x, int _y):  x(_x), y(_y) {};
};

float distance(pt a, pt b){
    return hypot(a.x - b.x, a.y - b.y);
}
