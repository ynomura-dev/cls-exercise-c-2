/************************************************
*
* C演習II レポート1用補助プログラム
*
* Author: Yasuharu Mizutani
*
*************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*************************************************
*
*    文字や文字列の種別を判定する関数
*
**************************************************/

/* 引数に指定した文字が空白系の文字であることを検査する */
static int isWhitespace(char c){
    return c==' ' || c=='\t' || c=='\n';
}

/* 引数に指定した文字が数字であることを検査する */
static int isNumberChar(char c){
    return '0' <= c && c <= '9';
}

/* 引数に指定した文字が演算子や括弧であることを検査する */
static int isSymbolChar(char c){
    switch (c){
        case '+': case '-': case '*': case '/': case '%':
        case '(': case ')': case '^': 
        case '[': case ']': case '{': case '}': 
        case '=': case '<': case '>': case '@':
        case '~': case '$': 
        case '!': case '#': case '&': case '?':
            return 1;
            break;
    }
    return 0;
}

/* 引数に指定した文字列が「符号無し数値」を表すことを検査する */
int isNumber(char *str){
    int i;
    int dotcnt=0;

    for (i=0; str[i]!='\0'; i++){
        if (isNumberChar(str[i])){
            /* nothing to do */
        }else if (str[i] == '.'){
            if (++dotcnt >= 2){
                return 0;
            }
        }else{
            return 0;
        }
    }
    return 1;
}


int isDouble(char *str){
    if (str[0]=='+' || str[0]=='-'){
        return isNumber(&str[1]);
    }else{
        return isNumber(str);
    }
}


int isOperator(char *str){
    return ( str[0]=='+' || str[0]=='-' || 
             str[0]=='*' || str[0]=='/' || str[0]=='%' || str[0]=='^'
           ) && str[1]=='\0';
}


/*************************************************
*
*    double型の値を文字列に変換する関数
*
**************************************************/

/* double型の値を10進数表記したときの有効桁数 */
#define DOUBLE_SIGNIFICANT_DIGITS  15

/* 実数xを10進数表示する際に有効桁DOUBLE_SIGNIFICANT_DIGITSで
 * 表示するために必要な小数点以下の桁数を返す． */
static int getPrecision(double x){
    int num;

    if (x < 0){
        x = -x;
    }
    if (x >= 1){
        num = DOUBLE_SIGNIFICANT_DIGITS;
        while (x>=1 && num>0){
            x /= 10;
            num--;
        }
    }else{
        if (x != 0){
            num = DOUBLE_SIGNIFICANT_DIGITS - 1;
            while (x < 1){
                x *= 10;
                num++;
            }
        }else{
            num = 1;
        }
    }
    return num;
}


/* double型を文字列表記したときの最大長．
 * DBL_MIN指数部(308)+有効桁(15)+符号(1)+小数点(1) = 325 
 * 念のために予備(25)を加えておく． */
#define D2S_MAX_STRLEN (325+25)

/* 最低限記憶しておきたい文字列の個数 */
#define D2S_MIN_STRNUM 1000

/* 引数に指定した実数値を文字列(内部領域)として返す */
char *ftoa(double x){

    /* 文字列を格納するバッファと現在位置(in static領域) */
    static char Buf[D2S_MIN_STRNUM * D2S_MAX_STRLEN];
    static int Index = 0;

    /* バッファの残りの要素数 */
    int remainSize = D2S_MIN_STRNUM * D2S_MAX_STRLEN - Index;

    int len;
    char *ret;

    if (remainSize < D2S_MAX_STRLEN){
        fprintf(stderr, "Error: dtos関数で使用するバッファを使い切りました．\n");
        exit(1);
    }

    sprintf(&Buf[Index], "%.*f", getPrecision(x), x);
    len = strlen(&Buf[Index]);

    ret = &Buf[Index];
    Index += len+1;
    return ret;
}



/****************************************************
*
*        キーボード入力関連
*
*****************************************************/

#define MAX_INPUT_STRLEN 512    /* 1回の入力の最大長 */
#define BUFCOUNT 64

/* 標準入力から1行分の文字列を読み込み，トークンに分割する．
 * 第1引数: token[]: 分割した各トークン(文字列)を格納する配列．
 * 第2引数: maxTokenNum: token[]の要素数．
 * 第3引数: 読み込んだトークンの個数．
 * 戻り値: 読み込んだトークンの個数．
 */
static int enter_core(char *token[], int maxTokenNum){
    static char buf[BUFCOUNT][MAX_INPUT_STRLEN * 2];
    static int k=-1;
    static int callcnt = 0;

    int i, j;
    char str[MAX_INPUT_STRLEN];
    int count;


    if (callcnt++ > 0){
        printf("\n");
    }
    printf("input> ");
    fflush(stdout);


    if (fgets(str, MAX_INPUT_STRLEN, stdin) == NULL){
        token[0] = NULL;
        count = -1;
        return -1;
    }

    i = 0;
    j = 0;
    k = (k+1)%BUFCOUNT;
    count = 0;
    while (str[i] != '\0'){

        if (isWhitespace(str[i])){
            i++;
            continue;

        } else if (str[i]=='q' || str[i]=='Q'){
            count = -1;
            return -1;

        } else if (isNumberChar(str[i]) || str[i]=='.'){
            int dotcnt = 0;

            token[(count)++] = &buf[k][j];

            while (isNumberChar(str[i]) || str[i] == '.'){
                if (str[i] == '.'){
                    dotcnt++;
                }
                buf[k][j++] = str[i++];
            }
            buf[k][j++] = '\0';

            if (dotcnt >= 2){
                fprintf(stderr, "Error: read(): 小数点が2個以上ある数値(%s)を読み込みました\n", buf[k]);
                exit(1);
            }
            if (buf[k][0]=='.' || buf[k][j-2]=='.' ){
                fprintf(stderr, "Error: read(): 実数(%s)の形式が不正です．\n", buf[k]);
                exit(1);
            }

        } else if (isSymbolChar(str[i])){
            token[(count)++] = &buf[k][j];
            buf[k][j++] = str[i++];
            buf[k][j++] = '\0';

        } else {
            if (str[i] == 27){
                printf("Error: read(): 未知の文字(コード%d)を検出しました\n", str[i]);
                printf("Error: read(): 矢印キーやDELキーなどを入力したのかもしれません\n");
            }else{
                printf("Error: read(): 未知の文字('%c', %d)を検出しました\n", str[i], str[i]);
            }
            exit(1);
        }

        if (count > maxTokenNum-1){
            fprintf(stderr, "Error: read(): 分割したトークンの数が多過ぎます．\n");
            exit(1);
        }
    }
    return count;
}

int enter(char *token[], int maxTokenNum){
    int r;
    r = enter_core(token, maxTokenNum);
    while (r == 0){
        r = enter_core(token, maxTokenNum);
    }
    return r;
}

