#include<stdio.h>
#include<string.h>
#define N 4

int main(void){

    char *str[N] = {"Apple", "apple", "banana", "orange"};
    int i, j, result;

    for (i=0; i<N; i++){
        for (j=0; j<N; j++){
            result = strcmp(str[i], str[j]);

            if (result == 0){
                printf("%s = %sです\n", str[i],str[j]);
            }else if (result > 0){
                printf("%s>%sです\n", str[i], str[j]);
            }else if (result < 0){
                printf("%s<%sです\n", str[i], str[j]);
            }
        }
    }
    return 0;
}
