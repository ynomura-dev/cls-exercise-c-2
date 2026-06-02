#include <stdio.h>

/* 2次元ベクトルを表す構造体 */
struct vector {
    double x;
    double y;
};

/* 引数に与えたベクトルを表示する */
void print_vector(struct vector v){
    printf("(%.2f, %.2f)\n", v.x, v.y);
}

/* init_vector関数の定義
* 引数はstruct vector型のアドレス（ポインタ），戻り値は無い．
* 引数で受け取ったアドレスにあるベクトルを(0.0, 0.0)に設定する．
*/
void init_vector(struct vector *p){
    p->x = 0.0;
    p->y = 0.0;
}

/* input_vector関数の定義
* 引数はstruct vector型のアドレス（ポインタ），戻り値は無い．
* キーボードから実数を2つ入力し（x，yと表記する），
* 引数で受け取ったアドレスにあるベクトルを(x, y)に設定する．
*/
void input_vector(struct vector *p){
    printf("x: ");
    scanf("%lf", &p->x);     //&より->の方が優先度高　&(p->x)のように処理されている
    printf("y: ");
    scanf("%lf", &p->y);
}

/* negate_vector関数の定義
* 引数はstruct vector型のアドレス（ポインタ），戻り値は無い．
* 引数で受け取ったアドレスにあるベクトルの xとy の符号を反転する．
*/
void negate_vector(struct vector *p){
    p->x = -(p->x);
    p->y = -(p->y);
}

/* ★の部分は自分で考えて記入してください．*/
/* ★以外の部分は変更せずにそのまま使用してください */
int main(void){
    struct vector v; 

    /* ベクトルvを初期化する */
    init_vector(&v);
    print_vector(v);

    /* ベクトルvのデータをキーボードから入力する */
    printf("input vector: ");
    input_vector(&v);
    print_vector(v);

    /* ベクトルvのデータの符号を反転する */
    printf("negate vector:\n");
    negate_vector(&v);
    print_vector(v);
    
    return 0;    
}

//変数toアドレス　　&変数　　例）&v
//アドレスto変数　　*ポインタ　例）*p