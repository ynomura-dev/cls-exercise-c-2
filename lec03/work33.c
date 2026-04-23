        #include <stdio.h>
        #include <stdlib.h>
        #include <string.h>

        // スタックに格納するデータの型（これを追加した）
        typedef char* STACK_TYPE;
        
        // スタックの実装部分
        #define STACK_SIZE 10
        
/*①*/  STACK_TYPE gStack[STACK_SIZE];
/*②*/  int gSNum = 0;         
        
/*③*/  void push(STACK_TYPE x){
            gStack[gSNum++] = x;
        }
        
/*④*/  STACK_TYPE pop(void){
            return gStack[--gSNum];
        }
        
        void printStack(void){
/*⑤*/      int i;
            printf("STACK[ ");
            for (i=0; i<gSNum; i++){
                printf("%s ", gStack[i]);
            }
            printf("]\n");
        }
        
/*⑥*/  int isStackEmpty(void){
            return gSNum == 0;
        }
        
/*⑦*/  int isStackFull(void){
            return gSNum == STACK_SIZE;
        }

        int isEnteredINIT(char* n){
            if (strcmp(n, "INIT") == 0){
                return 1;
            } else {
                return 0;
            }
        }

        int initStack(char* n){
            gSNum = 0;
            return 0;
        }

        // スタックの利用部分
/*⑧*/  int main(int argc, char *argv[]){
            if (argc == 1){
                fprintf(stderr, "error:プログラム引数が0です\n");
                return 1;
            } else {

                for (int i = 1; i < argc; i++){
                    if (isStackFull()){
                        fprintf(stderr, "error: スタックがフル状態です\n");
                        break;
                    } else {
                        printf("push %s : ", argv[i]);
                        push(argv[i]);
                        if (isEnteredINIT(argv[i])){
                            initStack(argv[i]);
                        }
                        printStack();
                    }
                }
            
                printf("=================\n");
            
                /* スタックが空状態になるまでpopし続ける */
                while (isStackFull()){
                    printf("pop %s  : ", pop());
                    printStack();
                }
            }
              
            return 0;
        }

