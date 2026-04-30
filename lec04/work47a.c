#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>   // gettimeofday関数を使用するのに必要

///////////////////////////////////////////////////////////////////////
// ある時刻からの経過時間(秒)を返す関数．
// C演習I(4学科,2025)のレポート2で使用した時間計測関数と同じ機能の関数．
///////////////////////////////////////////////////////////////////////
double now(void){
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec + tv.tv_usec/1000000.0;
}

//////////////////////////////
// キューの実装部
//////////////////////////////
#define QUEUE_SIZE 100000   // 今回はキューの大きさを10万にする

// work47a.cでは，単純な配列を使った実装(work41.cで作ったキュー）
// work47b.cでは，リングバッファを使った実装(work46.cで作ったキュー）


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
    return queue[0];
}

void printQueue(void){
    int i;
    printf("QUEUE[ ");
    for (i=0; i<=queue_rear; i++){
        printf("%d ", queue[i]);
    }
    printf("]\n");
}

////////////////////////////////
// キューの利用部
// 変更せずにこのまま使用する．
////////////////////////////////
int main(void){
    double begin, end;
    int n = 100000;
    QUEUE_TYPE tmp;

    // n(10万)個のデータをエンキューする時間を計測
    begin = now();
    for (int i=0; i<n; i++){
        enqueue(i);
    }
    end = now();
    printf("enqueue: %f 秒\n", end-begin);

    // n(10万)個のデータをデキューする時間を計測
    begin = now();
    for (int i=0; i<n; i++){
        tmp = dequeue();
    }
    end = now();
    printf("dequeue: %f 秒\n", end-begin);
    printf("最後にデキューした値: %d\n", tmp);

    return 0;
}