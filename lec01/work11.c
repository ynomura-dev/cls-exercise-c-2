#include <stdio.h>

int main(void) {
    int n, m, total;
    scanf("%d", &n);
    if (n < 0) return 1;
    total = n;
    while (1) {
        scanf("%d", &m);
        if (m < 0){
            printf("%d %d\n", n, total);
            break;
            }
        n += m;
        total *= m;
    }
}
