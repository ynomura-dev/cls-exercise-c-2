#include <stdio.h>
#define N 3

struct point {
    int x;
    int y;
};

int main(void) {
    struct point a[N];
    int i;
    for (i = 0; i < N; i++) {
        printf("%d番目の座標: ", i + 1);
        scanf("%d", &a[i].x);
        scanf("%d", &a[i].y);
    }

    for (i = 0; i < N; i++) {
        printf("%d番目: (%d, %d)\n", i + 1, a[i].x, a[i].y);
    }
    return 0;
}