#include <stdio.h>
#include "calcAverage.h"

double calcAverage(SCORE a[], int n){
    SCORE sum = 0;
    for (int i=0; i<n; i++){
        sum += a[i];
    }
    return (double)sum/n;
}