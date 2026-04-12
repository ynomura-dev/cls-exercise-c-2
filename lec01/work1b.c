#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <math.h> popを使うなら

int priority(char *operator){
    if (strcmp(operator, "||") == 0) return 1;
    if (strcmp(operator, "&&") == 0) return 2;
    if (strcmp(operator, "==") == 0) return 3;
    if (strcmp(operator, "+")  == 0) return 5;
    if (strcmp(operator, "-")  == 0) return 5;
    if (strcmp(operator, "*")  == 0) return 6;
    if (strcmp(operator, "/")  == 0) return 6;
    if (strcmp(operator, "%")  == 0) return 6;
    if (strcmp(operator, "^")  == 0) return 8;
    return -1;
}

int judge(char *op1, char *op2){
    int p1 = priority(op1);
    int p2 = priority(op2);

    if (p1 == -1 || p2 == -1) {
        return -1;
    }

    return p1 >= p2 ? 1 : 0; // 三項演算子忘れるな
}

int main(int argc, char *argv[]){

    if (argc != 3) {
        printf("エラー：プログラム引数を2つ指定してください\n");
        return 1;
    }

    int result = judge(argv[1], argv[2]);

    if (result == -1) {
        printf("エラー：未知の記号です\n");
        return 1;
    } else if (result == 1) {
        printf("s(%s)を先に適用します。\n", argv[1]);
    } else {
        printf("t(%s)を先に適用します。\n", argv[2]);
    }

    return 0;
}

/*v2
int priority(char *operator){
    if (strcmp(operator, "||") == 0) return 1;
    if (strcmp(operator, "&&") == 0) return 2;
    if (strcmp(operator, "==") == 0) return 3;
    if (strcmp(operator, "+")  == 0) return 5;
    if (strcmp(operator, "-")  == 0) return 5;
    if (strcmp(operator, "*")  == 0) return 6;
    if (strcmp(operator, "/")  == 0) return 6;
    if (strcmp(operator, "%")  == 0) return 6;
    if (strcmp(operator, "^")  == 0) return 8;
    return -1;
}

int main(int argc, char *argv[]){

    if (argc != 3) {
        printf("エラー：プログラム引数を2つ指定してください\n");
        return 1;
    }

    int p1 = priority(argv[1]);
    int p2 = priority(argv[2]);

    if (p1 == -1 || p2 == -1) {
        printf("エラー：未知の記号です\n");
        return 1;
    }

    if (p1 >= p2) {
        printf("s(%s)を先に適用します。\n", argv[1]);
    } else {
        printf("t(%s)を先に適用します。\n", argv[2]);
    }

    return 0;
}*/


/* v1

int priority(char *operator){
    if (strcmp(operator, "||") == 0) return 1;
    if (strcmp(operator, "&&") == 0) return 2;
    if (strcmp(operator, "==") == 0) return 3;
    if (strcmp(operator, "+")  == 0) return 5;
    if (strcmp(operator, "-")  == 0) return 5;
    if (strcmp(operator, "*")  == 0) return 6;
    if (strcmp(operator, "/")  == 0) return 6;
    if (strcmp(operator, "%")  == 0) return 6;
    if (strcmp(operator, "^")  == 0) return 8;
    return -1;
}

int main(int argc, char *argv[]){
    int result = 0;

    if (argc != 3) {
        printf("error:expected 2 values.\n");
    } else {
        for (int i = 1; i < argc; i++){             //下の行をシンプルにするために0はじめにしたが、可読性悪いならここと下行を素直に書き直す
            result += pow(-1, i) * priority(argv[i]);
            if (priority(argv[i]) == -1) printf("kigou\n");
        }
        
        if (result < 0) {
            printf("s(%s)を先に適用します。\n", argv[1]);
        } else {
            printf("t(%s)を先に適用します。\n", argv[2]); //argvは[0]に実行ファイル名が入るので1ずれる
        }
    }
}

*/