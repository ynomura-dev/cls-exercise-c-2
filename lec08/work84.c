#include <stdio.h>
#include <stdlib.h>

struct vector3 {
    double x;
    double y;
    double z;
};

int main(void) {
    struct vector3 *p;

    p = malloc(sizeof(struct vector3));
    if (p == NULL) {
        fprintf(stderr, "エラー： malloc失敗\n");
        exit(1);
    }

    p->x = 5.28;
    p->y = -7.16;
    p->z = 3.14;

    printf("p = (%.2f, %.2f, %.2f)\n", p->x, p->y, p->z);

    free(p);
    return 0;
}