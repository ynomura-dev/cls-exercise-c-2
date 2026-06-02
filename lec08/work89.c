#include <stdio.h>

/* typedefを用いてstruct vector型をVector型に定義する */
/* （構造体型をtypedefする際の典型的な書き方）        */
typedef struct vector {
    double x;
    double y;
} Vector;

int main(void){
    Vector v;     /* struct vector型の代わりに， */
                  /* typedefしたVector型を用いる */
    v.x = 12.3;
    v.y = 45.6;
    printf("v = (%.3f, %.3f)\n", v.x, v.y);

    return 0;
}