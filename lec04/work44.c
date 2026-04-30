#include <stdio.h>
#include <stdlib.h>



typedef int QUEUE_TYPE;
#define QUEUE_SIZE 10

QUEUE_TYPE queue[QUEUE_SIZE];
int queue_rear = -1;

void printQueue(int tabs){
    int i, j;
    // tabs回分タブを出力
    for (j = 0; j < tabs; j++){
        printf("\t");
    }
    printf("QUEUE[ ");
    for (i = 0; i <= queue_rear; i++){
        printf("%d ", queue[i]);
    }
    printf("]\n");
}

void errorExit(const char *message){
    fprintf(stderr, "s%s\n", message);
    exit(1);
}

int isQueueEmpty(void){
    return queue_rear == -1;
}

int isQueueFull(void){
    return queue_rear == QUEUE_SIZE - 1;
}

void enqueue(QUEUE_TYPE x){
    if (isQueueFull()) {
        fprintf(stderr, "エラー: キューがフル状態でenqueueはできません\n");
        exit(1);
    }
    queue[++queue_rear] = x;
}

QUEUE_TYPE dequeue(void){
    QUEUE_TYPE temp = queue[0];
    if (isQueueEmpty()) {
        fprintf(stderr, "エラー: キューが空状態でdequeueはできません\n");
        exit(1);
    }
    for (int i = 0; i < queue_rear; i++) {
        queue[i] = queue[i + 1];
    }
    queue_rear--;
    return temp;
}


void initQueue(void){
    queue_rear = -1;
}

int main(int argc, char *argv[]){
    QUEUE_TYPE x;
    int i = 1;

    if (argc < 2){
        errorExit("引数を指定してください");
        exit(1);
    }

    initQueue();
    for (i = 1; i < argc; i++){
        if (isQueueFull()) break;
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

