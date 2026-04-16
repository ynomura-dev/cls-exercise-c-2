#include <stdio.h>

int main(void){
    int a, b;
    int p=10, q=10;

    a = p++ + 100;
    printf("a=%d, p=%d\n", a, p);

    b = ++q + 100;
    printf("b=%d, q=%d\n", b, q);

    return 0;
}