#include <stdio.h>

int main (void){
    int a;
    int*pa;

    printf("=== step1 ===\n");
    a = 7;
    pa = &a;
    printf("a = %d\n", a);
    printf("pa = %p\n", (void*)pa);
    printf("*pa = %d\n", *pa);

    printf("=== step2 ===\n");
    a = 300;
    printf("a = %d\n", a);
    printf("*pa = %d\n", *pa);

    printf("=== step3 ===\n");
    *pa = 500;
    printf("a = %d\n", a);
    printf("*pa = %d\n", *pa);

    return 0;
}