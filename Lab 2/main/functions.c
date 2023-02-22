//
// Created by Administrator on 2023-02-22.
//

#include <malloc.h>
#include "functions.h"
int numberOfEvenNumbers(int n, int *pArray){
    int even = 0;
    for (int i = 0; i < n; ++i) {
        if(pArray[i] % 2 == 0)
            even++;
    }
    return even;
}
int sumOfPositiveNumbers(int n, int *pArray){
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        if (pArray[i] >= 0)
            sum += pArray[i];
    }
    return sum;
}
void allocateMemoryForMatrix2(int rows, int cols, int ***dpMatrix){
    *dpMatrix = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; ++i) {
        (*dpMatrix)[i] = (int*)malloc(cols * sizeof(int));
    }
}
