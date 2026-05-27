#include <stdio.h>

/* 2次元座標上の点を表す構造体の定義 */
struct Point {
    int x;
    int y;
};

struct Point get_point(int x, int y){
    struct Point p;
    p.x = x;
    p.y = y;
    return p;
}

void print_point(struct Point p){
    printf("(%d, %d)\n", p.x, p.y);
    return;
}

struct Point input_point(){
    struct Point p;
    scanf("%d", &p.x);
    scanf("%d", &p.y);
    return p;
}

struct Point get_middle_point(struct Point p1, struct Point p2){
    struct Point p;
    p.x = (p1.x + p2.x) / 2;
    p.y = (p1.y + p2.y) / 2;
    return p;
}

/*************************************************
* main関数は変更せずに使用すること．
* 指定通りの関数を作成すれば，main関数を以下の状態
* から一切変更せずに正しく動作するはずです．
* ★main関数をよく読んで，どのように関数が使われて
*   いるかをよく確認してください．
**************************************************/
int main(void){
    struct Point p1;  /* 定義した構造体型「struct Point」は  */
    struct Point p2;  /* 型名としてintやdoubleなどと同様に */
    struct Point p3;  /* 使うことができる */

    /* 点p1の座標を(40, 50)に設定する */
    p1 = get_point(40, 50);
    printf("p1 = ");
    print_point(p1);

    /* 点p2の座標をキーボードから入力する */
    printf("input: ");
    p2 = input_point();
    printf("p2 = ");
    print_point(p2);

    /* 点p1と点p2の中点の座標を点p3に設定する */
    p3 = get_middle_point(p1, p2);
    printf("p3 = ");
    print_point(p3);

    return 0;
}