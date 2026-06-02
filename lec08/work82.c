#include <stdio.h>

struct vector {
    double x;
    double y;
};

int main(void) {
    struct vector v;
    struct vector *p;       //*pの"*"はポインタから値を取り出し用いるという意　ここより下のほうが分かりやすいかも"

    p = &v;

    (*p).x = 100.0;
    (*p).y = 200.0;
    printf("v = (%3f, %3f)\n", v.x, v.y);

    p->x = 300.0;           //p->xは(*p).xと同じ意味
    p->y = 400.0;
    printf("v = (%3f, %3f)\n", v.x, v.y);
    
    return 0;
}