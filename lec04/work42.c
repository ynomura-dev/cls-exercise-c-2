#include <stdio.h>
#include <stdlib.h>

// キューの実装部
// この部分を教科書を参考に作成する
#define QUEUE_SIZE 10

typedef int QUEUE_TYPE;
QUEUE_TYPE queue[QUEUE_SIZE];

int queue_rear = -1;    //今回はインデックスの最後を表すようにしてみた。次入れるとこじゃなくて。こっちだと空が分かりやすい。前回と違うから注意。

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

void printQueue(void){
    int i;
    for (i=0; i<=queue_rear; i++){
        printf("%d ", queue[i]);
    }
}


int main(int argc, char *argv[]){
    QUEUE_TYPE input[QUEUE_SIZE];
    int input_count = 0;

    for(int i = 1; i < argc; i++){
        input[input_count++] = atoi(argv[i]);
    }

    for(int i = 0; i < input_count; i++){
        if(input[i] % 2 != 0) enqueue(input[i]);
    }
    printQueue();

    for(int i = 0; i < input_count; i++){
        if(input[i] % 2 == 0) enqueue(input[i]);
    }
    printQueue();



    printf("\n");
    return 0;
}