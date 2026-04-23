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
    gStack[gSNum++] = p;
}

Point pop(void){
    if (isStackEmpty()){
        printf("空状態でpopしようとしました\n");
        exit(1);
    }
    return gStack[--gSNum];
}

void readMap(int map[][WIDTH], int rowsize){
    int i, j;
    for (i = 0; i < rowsize; i++){
        for (j = 0; j < WIDTH; j++){
            scanf("%d", &map[i][j]);
        }
    }
}

int main(void){
    int map[HEIGHT][WIDTH];

    readMap(map, HEIGHT);

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

        if (map[p.x][p.y] == 1){
            continue;
        }

        map[p.x][p.y] = 1;

        if (p.x + 1 < HEIGHT){
            Point down = {p.x + 1, p.y};
            push(down);
        }

        if (p.y + 1 < WIDTH){
            Point right = {p.x, p.y + 1};
            push(right);
        }
    }

    if (found){
        printf("経路あり\n");
    } else {
        printf("経路なし\n");
    }

    return 0;
}
