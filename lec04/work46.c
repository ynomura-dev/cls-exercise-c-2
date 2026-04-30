#include <stdio.h>
#include <stdlib.h>

// キューの実装部
// この部分を教科書を参考に作成する
#define QUEUE_SIZE (10+1)

typedef int QUEUE_TYPE;
QUEUE_TYPE queue[QUEUE_SIZE];

int queue_front = 0;
int queue_rear = 0;

void errorExit(const char *message){
    fprintf(stderr, "%s\n", message);
    exit(1);
}

int isQueueEmpty(void){ //修正済み
    return queue_front % QUEUE_SIZE == queue_rear;
}

int isQueueFull(void){ //修正済み
    return (queue_rear + 1) % QUEUE_SIZE == queue_front;
}

int next(int i){
    return (i + 1) % QUEUE_SIZE;
}

void enqueue(QUEUE_TYPE x){  //修正済み
    if (isQueueFull()) {
        fprintf(stderr, "エラー: キューがフル状態でenqueueはできません\n");
        exit(1);
    }
    queue[queue_rear] = x;
    queue_rear = next(queue_rear);
}

QUEUE_TYPE dequeue(void){
    if (isQueueEmpty()) {
        errorExit("エラー: キューが空状態でdequeueはできません");
    }
    QUEUE_TYPE temp = queue[queue_front];  // 先に値を取る
    queue_front = next(queue_front);       // その後frontを進める
    return temp;
}

void printQueue(void){
    int i;
    printf("QUEUE[ ");
    for (i=queue_front; i!=queue_rear; i=next(i)){
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