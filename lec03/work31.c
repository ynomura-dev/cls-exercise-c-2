#include<stdio.h>
int main(void){
    printf("これは標準出力に表示されます.\n");
    fprintf(stdout, "これも標準出力に表示されます.\n");
    fprintf(stderr, "これは標準エラー出力に表示されます.\n");
    return 0;
}