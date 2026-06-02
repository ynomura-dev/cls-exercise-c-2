#include <stdio.h>
#include <stdlib.h>

struct vector3 {
    double x;
    double y;
    double z;
};

struct vector3 *create_vector(double x, double y, double z){
    struct vector3 *p;

    p = malloc(sizeof(struct vector3));
    if (p == NULL) {
        fprintf(stderr, "エラー： malloc失敗\n");
        exit(1);
    }

    p->x = x;
    p->y = y;
    p->z = z;

    return p;
}
void print_vector(struct vector3 *v){
    printf("vector: (%.2f, %.2f, %.2f)\n", v->x, v->y, v->z);
}
int main(void){
    struct vector3 *p;
    p = create_vector(5.28, -7.16, 3.14);  /* 関数内部でmallocで確保 */
    print_vector(p);
    free(p);                   /* mallocで取得した領域を解放 */
    return 0;
}