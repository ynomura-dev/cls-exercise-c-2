#include <stdio.h>

struct Point{
    int x;
    int y;
};

int get_point(struct Point *p){
    scanf("%d", &(*p).x);
    scanf("%d", &(*p).y);
    return 0;
}

int is_same_point(struct Point p1, struct Point p2){
    return p1.x == p2.x && p1.y == p2.y;
}

int is_x_symmetry(struct Point p1, struct Point p2){
    return p1.x == -p2.x && p1.y == p2.y;
}

int is_y_symmetry(struct Point p1, struct Point p2){
    return p1.x == p2.x && p1.y == -p2.y;
}

int is_origin_symmetry(struct Point p1, struct Point p2){
    return p1.x == -p2.x && p1.y == -p2.y;
}

int is_equal_distance_from_origin(struct Point p1, struct Point p2){
    return p1.x * p1.x + p1.y * p1.y == p2.x * p2.x + p2.y * p2.y;
}

int print_result(struct Point p1, struct Point p2){
    if (is_same_point(p1, p2)){
        printf("同じ点です\n");
    } else if (is_x_symmetry(p1, p2)){
        printf("X軸に対して対称です\n");
    } else if (is_y_symmetry(p1, p2)){
        printf("Y軸に対して対称です\n");
    } else if (is_origin_symmetry(p1, p2)){
        printf("原点に対して対称です\n");
    } else if (is_equal_distance_from_origin(p1, p2)){
        printf("原点からの距離が等しいです\n");
    } else {
        printf("いずれの関係にもありません\n");
    }
    return 0;
}

int main(void){

    struct Point p1, p2;
    get_point(&p1);
    get_point(&p2);
    print_result(p1, p2);

    return 0;

}