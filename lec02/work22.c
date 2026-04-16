#include <stdio.h>
#include <stdlib.h>     //exit関数のため

#define NUM 4

int main(int argc, char *argv[]){
    if (argc != NUM+1) {
        printf("エラー：プログラム引数が4つではありません\n");
        exit(1);
    }

    for(int i = 1; i < NUM + 1; i++) {
        printf("プログラム引数 = [%s]\n", argv[i]);
    }
}

/*

#include <stdio.h>
#include <stdlib.h>     //exit関数のため

#define NUM 4

int main(int argc, char *argv[]){
    if (argc != NUM+1) {
        printf("Error\n");
        exit(1);
    }

    for(int i = 1; i < NUM + 1; i++) {
        printf("ans[%s]\n", argv[i]);
    }
}

*/