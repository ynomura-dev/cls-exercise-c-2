#include <stdio.h>
#include "myerror.h"

int main(int argc, char *argv[]){
    if (argc != 4){
        error("引数が3つではありません");
    }
    printf("argv[1] = %s\n", argv[1]);
    printf("argv[2] = %s\n", argv[2]);
    printf("argv[3] = %s\n", argv[3]);

    return 0;
}