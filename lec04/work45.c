#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE 8

int begin = 0;
int end = 1;


void errorExit(const char *message){
    fprintf(stderr, "%s\n", message);
    exit(1);
}

int isQueueEmpty(void){
    return end == begin;
}

int isQueueFull(void){
    return (end + 1) % BUFSIZE == begin;
}

// リングバッファにおける添字iの次の添字を返す
int next(int i){
    if (!isQueueFull()){
        if (i == BUFSIZE - 1){
            return 0;
        } else {
            return i + 1;
        }
    } else {
        errorExit("エラー: キューがフル状態でenqueueはできません");
    }
}

// main関数は修正せずにこのまま使用する
int main(void){
    int buf[BUFSIZE] = {0};
    int begin, end, i;

    printf("先頭の添字を入力してください: ");
    scanf("%d", &begin);
    printf("末尾の添字を入力してください: ");
    scanf("%d", &end);

    // リングバッファの先頭から末尾までを順に処理する
    // 注意: 継続条件に i<=end と書いてはいけない．先頭と末尾
    //       添字の大小が逆転している場合に不具合が起こるため．
    for (i=begin; i!=end; i=next(i)){
        printf("入力してください: ");
        scanf("%d", &buf[i]);
    }

    printf("配列の内容: ");
    for (i=0; i<BUFSIZE; i++){
        printf("%d ", buf[i]);
    }
    printf("\n");

    return 0;
}