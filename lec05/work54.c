#include <stdio.h>
#include <stdlib.h>    /* fprintf関数, exit関数を使うために必要 */
#include <string.h>    /* strcmp関数を使うために必要 */


void errorExit(const char *message){
    fprintf(stderr, "%s\n", message);
    exit(1);
}



/*****************************************************************
* リストの実装部
*****************************************************************/
#define LIST_SIZE 100000

typedef int LIST_TYPE;
typedef int POSITION;
LIST_TYPE list[LIST_SIZE];
POSITION position;

int listLength (void){
    return position;
}

int isListEmpty(void){
    if (position == 0){
        return 1;
    }
    return 0;
}

int isListFull(void){
    if (position == LIST_SIZE){
        return 1;
    }
    return 0;
}

void insert(POSITION pos, LIST_TYPE x){
    if (pos < 0 || pos >= LIST_SIZE){
        errorExit("エラー: insert: 位置が正しくありません");
        return;
    }
    if (isListEmpty()){
        errorExit("エラー: insert: リストは通常状態ではありません");
        return;
    } 
    if (isListFull()){
        errorExit("エラー: insert: フル状態ではリストに挿入できません");
        return;
    }
    if (pos > position){
        errorExit("エラー: insert: 挿入位置がリストの末尾を超えています");
        return;
    }

    for (int i = position; i > pos; i--){
        list[i] = list[i-1];
    }
    list[pos] = x;
    position++;
}

void append(LIST_TYPE x){
    if (isListFull()){
        errorExit("エラー: append: フル状態ではリストに追加できません");
        return;
    }
    
    list[position++] = x;
}

LIST_TYPE delete(POSITION pos){
    if (pos < 0 || pos >= position){
        errorExit("エラー: delete: 位置が正しくありません");
        return -1;
    }
    if (isListEmpty()){
        errorExit("エラー: delete: リストは通常状態ではありません");
        return -2;
    }

    LIST_TYPE deleted = list[pos];
    for (int i = pos; i < position - 1; i++){
        list[i] = list[i+1];
    }
    position--;
    return deleted;
}

LIST_TYPE retrive(POSITION pos){
    if (pos < 0 || pos >= position){
        errorExit("エラー: retrive: 位置が正しくありません");
        return -1;
    }
    if (isListEmpty()){
        errorExit("エラー: retrive: リストは通常状態ではありません");
        return -2;
    }

    return list[pos];
}

LIST_TYPE replace(POSITION pos, LIST_TYPE new){
    if (pos < 0 || pos >= position){
        errorExit("エラー: replace: 位置が正しくありません");
        return -1;
    }
    if (isListEmpty()){
        errorExit("エラー: replace: リストは通常状態ではありません");
        return -2;
    }

    LIST_TYPE old = list[pos];
    list[pos] = new;
    return old;
}

void initList(void){
    position = 0;
}

void printList(void){
    printf("LIST[ ");
    for (int j = 0; j < position; j++){
        printf("%d ", list[j]);
    }
    printf("]\n");
}

int countPositiveMultipleOf3or5(void){
    int count = 0;

    for (int i = 0; i < position; i++){
        int n = list[i];
        if (n > 0 && (n % 3 == 0 || n % 5 == 0)){
            count++;
        }
    }

    return count;
}



/*****************************************************************
* リストの利用部
* (1) プログラム引数に"append","insert"を指定し，各操作を実行する．
*      - appendの直後には追加する整数を指定するものとする．
*      - insertの直後には挿入する位置と整数を指定するものとする．
*      - これらの形式が誤っている場合の動作は保証しない．
* (2) work52ではこのmain関数は修正せずにそのまま使用すること．
* (3) main関数の処理内容を理解した上で使用すること．
*****************************************************************/
int main(int argc, char *argv[]){
    int i;
    LIST_TYPE x;
    POSITION pos;

    for (i=1; i<argc; i++){
        if (strcmp(argv[i], "append") == 0){
    x = atoi(argv[++i]);
    printf("append(%d)\n", x);
    append(x);

    }else if (strcmp(argv[i], "insert") == 0){
        pos = atoi(argv[++i]);
        x = atoi(argv[++i]);
        printf("insert(%d, %d)\n", pos, x);
        insert(pos, x);

    }else if (strcmp(argv[i], "delete") == 0){
        pos = atoi(argv[++i]);
        printf("delete(%d)\n", pos);
        delete(pos);

    }else if (strcmp(argv[i], "retrive") == 0){
        pos = atoi(argv[++i]);
        printf("retrive(%d) => %d\n", pos, retrive(pos));
    }else if (strcmp(argv[i], "replace") == 0){
        pos = atoi(argv[++i]);
        x = atoi(argv[++i]);
        printf("replace(%d, %d) => %d\n", pos, x, replace(pos, x));
    }else{
        fprintf(stderr, "エラー: 不明な操作です(%s)\n", argv[i]);
        exit(1);
    }


        printf("  ==> ");
        printList();
    }
    
    printf("%d 個です", countPositiveMultipleOf3or5());

    return 0;
}