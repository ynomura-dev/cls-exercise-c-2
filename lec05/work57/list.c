#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"



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

LIST_TYPE replace(POSITION pos, LIST_TYPE new_value){
    if (pos < 0 || pos >= position){
        errorExit("エラー: replace: 位置が正しくありません");
        return -1;
    }
    if (isListEmpty()){
        errorExit("エラー: replace: リストは通常状態ではありません");
        return -2;
    }

    LIST_TYPE old_value = list[pos];
    list[pos] = new_value;
    return old_value;
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



