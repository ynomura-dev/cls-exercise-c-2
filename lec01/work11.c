#include <stdio.h>

int main(void) {
    int n;
    int sum = 0;
    int product = 1;
   
    while (1) {
        scanf("%d", &n);
        if (n <= 0){
            printf("%d %d\n", sum, product);
            return 0;
            }
        sum += n;
        product *= n;
    }
}
