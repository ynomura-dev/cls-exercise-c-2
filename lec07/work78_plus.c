#include <stdio.h>

struct Point {
    int x;
    int y;
};

/* エラーコード */
#define SUCCESS 0
#define ERR_INPUT -1

int read_point(struct Point *p) {
    if (p == NULL) return ERR_INPUT;
    if (scanf("%d", &(*p).x) != 1) return ERR_INPUT;
    if (scanf("%d", &(*p).y) != 1) return ERR_INPUT;
    return SUCCESS;
}

int is_same(struct Point p1, struct Point p2) {
    return p1.x == p2.x && p1.y == p2.y;
}

int is_x_symmetric(struct Point p1, struct Point p2) {
    return p1.x == -p2.x && p1.y == p2.y;
}

int is_y_symmetric(struct Point p1, struct Point p2) {
    return p1.x == p2.x && p1.y == -p2.y;
}

int is_origin_symmetric(struct Point p1, struct Point p2) {
    return p1.x == -p2.x && p1.y == -p2.y;
}

int is_equidistant_from_origin(struct Point p1, struct Point p2) {
    return p1.x * p1.x + p1.y * p1.y == p2.x * p2.x + p2.y * p2.y;
}

int print_relation(struct Point p1, struct Point p2) {
    if (is_same(p1, p2))
        printf("同じ点です\n");
    else if (is_x_symmetric(p1, p2))
        printf("X軸に対して対称です\n");
    else if (is_y_symmetric(p1, p2))
        printf("Y軸に対して対称です\n");
    else if (is_origin_symmetric(p1, p2))
        printf("原点に対して対称です\n");
    else if (is_equidistant_from_origin(p1, p2))
        printf("原点からの距離が等しいです\n");
    else
        printf("いずれの関係にもありません\n");
    return SUCCESS;
}

int main(void) {
    struct Point p1, p2;

    if (read_point(&p1) != SUCCESS) {
        fprintf(stderr, "p1の入力エラー\n");
        return 1;
    }
    if (read_point(&p2) != SUCCESS) {
        fprintf(stderr, "p2の入力エラー\n");
        return 1;
    }

    print_relation(p1, p2);
    return 0;
}