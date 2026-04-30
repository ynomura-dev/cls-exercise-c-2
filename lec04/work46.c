#include <stdio.h>
#include <stdlib.h>

// キューの実装部
// この部分を教科書を参考に作成する
#define QUEUE_SIZE 10+1

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
    printf("QUEUE[ ");
    for (i=0; i<=queue_rear; i++){
        printf("%d ", queue[i]);
    }
    printf("]\n");
}

// キューの利用部
// 今回はmain関数は変更せずにこのまま用いる
int main(void){
    QUEUE_TYPE a;
    int i;

    // キューがフル状態になるまで，キーボードから入力した整数をエンキューし，
    // その都度，キューの内容を表示する
    printf("==========================================\n");
    printf("キューがフル状態になるまでエンキューします\n");
    while (!isQueueFull()){
        scanf("%d", &a);
        enqueue(a);
        printf("enqueue(%2d) : ", a);
        printQueue();
    }
    printf("キューがフル状態になりました\n");

    printf("==========================================\n");
    printf("3回デキューします\n");
    for (i=0; i<3; i++){
        a = dequeue();
        printf("dequeue() %2d : ", a);
        printQueue();
    }

    printf("==========================================\n");
    printf("2回エンキューします\n");
    for (i=0; i<2; i++){
        scanf("%d", &a);
        enqueue(a);
        printf("enqueue(%2d) : ", a);
        printQueue();
    }

    // キューが空状態になるまで，キーボードから入力した整数をデキューし，
    // その都度，キューの内容を表示する
    printf("==========================================\n");
    printf("キューが空状態になるまでデキューします\n");
    while (!isQueueEmpty()){
        a = dequeue();
        printf("dequeue() %2d : ", a);
        printQueue();
    }
    printf("キューが空状態になりました\n");

    return 0;
}