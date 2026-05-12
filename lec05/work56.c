#include <stdio.h>
#include "calcAverage.h"

int main(void){
    SCORE data1[5] = {80, 50, 65, 45, 85};
    SCORE data2[7] = {100, 83, 46, 75, 62, 50, 90};
    printf("data1の平均: %f\n", calcAverage(data1, 5) );
    printf("data2の平均: %f\n", calcAverage(data2, 7) );
    return 0;
}