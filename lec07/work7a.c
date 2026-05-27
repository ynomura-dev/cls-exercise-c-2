#include <stdio.h>
#include <stdlib.h>

struct Goods {
    int id;
    char name[128];
    int unit_price;
};

int make_goods_list(struct Goods *goods, int n){
    for (int i=0; i<n; i++){
        scanf("%d", &goods[i].id);
        scanf("%s", goods[i].name);
        scanf("%d", &goods[i].unit_price);
    }
    return 0;
}

int print_goods_list(struct Goods *goods, int n, int threshold){
    int count = 0;
    for (int i=0; i<n; i++){
        if (threshold < goods[i].unit_price){
            printf("%s,%d,%d\n",
                goods[i].name, goods[i].id, goods[i].unit_price);
            count++;
        }
    }
    printf("%d行出力しました\n", count);
    return 0;
}

int main(int argc, char *argv[]){

    if (argc != 2){
        fprintf(stderr, "エラー: %s プログラム引数を1つ指定してください\n", argv[0]);
        return 1;
    }

    int n;
    scanf("%d", &n);

    struct Goods goods[n];

    make_goods_list(goods, n);
    print_goods_list(goods, n, atoi(argv[1]));

    return 0;
}