#include <stdio.h>
#define N 64

int main(void){
    char s[N];
    char *p;

    scanf("%s", s); //アドレス演算子は不要(配列名は配列の先頭アドレスを表すため)
    p = s; //アドレス演算子は不要(配列名は配列の先頭アドレスを表すため)
    printf("s = [%s]\n", s);
    printf("p = [%s]\n", p);

    return 0;
}