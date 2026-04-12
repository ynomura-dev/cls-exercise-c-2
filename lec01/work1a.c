#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    double sum = 0;

    if (argc < 3) {
        printf("エラー: プログラム引数を2つ以上指定してください\n");
    } else {
        for (int i = 1; i < argc; i++) {
            sum += atof(argv[i]);
        }
    }

    printf("%.3f\n", sum/(argc-1)); 
}