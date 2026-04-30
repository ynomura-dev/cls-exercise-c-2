#include <stdio.h>
#include <stdlib.h>

// キューの実装部
// この部分を教科書を参考に作成する
#define QUEUE_SIZE 10

typedef char* QUEUE_TYPE;
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
    printf("QUEUE[ ");
    for (i=0; i<=queue_rear; i++){
        printf("%s ", queue[i]);
    }
    printf("]\n");
}

int isIntString(char *str){
    // 文字列を構成する文字を1文字ずつ終端まで調べる
    for (int i=0; str[i]!='\0'; i++){
        if ('0' <= str[i] && str[i] <= '9'){
            // 数字であれば何もしない 
        }else{
            return 0;
        }
    }
    return 1;
}

int main(int argc, char *argv[]){
    QUEUE_TYPE input[QUEUE_SIZE];
    int input_count = 0;

    for(int i = 1; i < argc; i++){
        if (!isIntString(argv[i])) {
            enqueue(argv[i]);
            printQueue();
        }
    }

    printf("\n");
    return 0;
}