#include <stdio.h>

void swap(int *p, int *q){
    int temp = *p;
    *p = *q;
    *q = temp;
}

int main(void){
    int a, b;
    int i;

    scanf("%d", &a);
    scanf("%d", &b);

    /* aの方が小さい値になるようにする */
    if (a>b){
            swap(&a, &b);
    }

    /* aからbまでの整数を列挙する */
    for (i=a; i<=b; i++){
        printf("%d ", i);
    }
    printf("\n");

    return 0;
}