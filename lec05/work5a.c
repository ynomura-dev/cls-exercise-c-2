#include <stdio.h>
#include <stdlib.h>
#include "queue.h"


int main(int argc, char *argv[]){
    QUEUE_TYPE x;
    int i = 1;

    if (argc < 2){
        errorExit("引数を指定してください");
    }

    initQueue();
    for (i = 1; i < argc; i++){
        if (isQueueFull()) {
            break;
        }

        x = atoi(argv[i]);
        printf("1つのプログラム %3d を追加します\n", x);
        enqueue(x);
        printf("enqueue(%d)", x);
        printQueue(2);
    }

    printf("***** 時分割制御を開始します *****\n");
    while (!isQueueEmpty()){
        x = dequeue();
        printf("dequeue() %d", x);
        printQueue(2);
        if (x-10 > 0){
            printf("enqueue(%d - 10)", x);
            enqueue(x-10);
            printQueue(1);
        } else {
            printf(" 一つのプログラムを終了しました\n");
        }
    }
    return 0;
}

