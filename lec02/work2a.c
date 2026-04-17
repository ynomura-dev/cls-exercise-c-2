#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 2000
#define HEIGHT 10
#define WIDTH 12

typedef struct {
    int x;
    int y;
} Point;

Point gStack[STACK_SIZE];
int gSNum = 0;

int isStackEmpty(){
    return gSNum == 0;
}

int isStackFull(){
    return gSNum == STACK_SIZE;
}

void push(Point p){
    if (isStackFull()){
        printf("エラー: これ以上pushできません\n");
        exit(1);
    }
    gStack[gSNum++] = p;    //これでポイント全体がコピー
}

Point pop(void){
    if (isStackEmpty()){
        printf("経路なし\n");
        exit(1);
    }
    return gStack[--gSNum];
}

int main(void){
    int map[HEIGHT][WIDTH];

    for(int i = 0; i < HEIGHT; i++){
        for(int j = 0; j < WIDTH; j++){
            scanf("%d", &map[i][j]);
        }
    }                                   //よく見たらC演習２のウェブサイトにあった。次から確認しよう :(

    Point START = {1, 1};
    Point GOAL  = {8, 10};

    int found = 0;

    push(START);

    while (!isStackEmpty() && found == 0){
        Point p = pop();

        if (p.x == GOAL.x && p.y == GOAL.y){
            found = 1;
            break;
        }

        if (map[p.x][p.y] == 2){    // 訪問済みロジック :)
            continue;
        }
        map[p.x][p.y] = 2;

        if (p.x + 1 < HEIGHT){
            push((Point){p.x + 1, p.y});
        }

        if (p.y + 1 < WIDTH){
            push((Point){p.x, p.y + 1});
        }

        if (p.x - 1 >= 0){
            push((Point){p.x - 1, p.y});
        }

        if (p.y - 1 >= 0){
            push((Point){p.x, p.y - 1});
        }
    }
    
    if (found){
        printf("経路あり\n");
    } else {
        printf("経路なし\n");
    }

    return 0;
}

