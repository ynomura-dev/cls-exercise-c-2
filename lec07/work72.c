#include <stdio.h>
#define N 10

void init(int *p){
    *p = 0;
}

int main(void){
    int i, x;
    int a[N];

    init(&x);
    printf(("x = %d\n"), x);

    printf("a = (");
    for (i=0; i<N; i++){
        init(&a[i]);
        printf("%d ", a[i]);
    }
    printf(")\n");
    return 0;
}