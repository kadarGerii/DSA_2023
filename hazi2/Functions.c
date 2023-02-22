//
// Created by Administrator on 2023-02-21.
//

#include "Functions.h"
float average(int n, int *pArray){
    //if(pArray == NULL) return -1;
    int counter = 0;
    for (int i = 0; i < n; ++i) {
        counter += pArray[i];
    }
    return (float)counter / n;
}
int numberOfOddNumbers(int n, int *pArray){
    int countOdd = 0;
    for (int i = 0; i < n; ++i) {
        if(pArray[i]%2==0) countOdd++;
    }
    return countOdd;
}
int productOfNegativeNumbers(int n, int *pArray){
    int negative = 1;
    for (int i = 0; i < n; ++i){
        if(pArray[i] < 0) negative *= pArray[i];
    }
    return negative;
}
int maximumValueOfColumn(int rows, int columnIndex, int **pMatrix){
    int maxValue = pMatrix[0][columnIndex];
    for (int i = 1; i < rows; ++i) {
        if(pMatrix[i][columnIndex] > maxValue) maxValue = pMatrix[i][columnIndex];
    }
    return maxValue;
}
int* columnMaximums(int rows, int cols, int **pMatrix){
    int *maxValues = (int*)malloc(cols * sizeof(int));
    for (int j = 0; j < cols; j++) {
        maxValues[j] = maximumValueOfColumn(rows, j, pMatrix);
    }
    return maxValues;
}
int maximumValueOfMatrix(int rows, int cols, int **pMatrix){
    int maximum = pMatrix[0][0];
    for (int i = 1; i < rows; ++i) {
        for (int j = 1; j < cols; ++j) {
            if (maximum > pMatrix[i][j]) {
                maximum = pMatrix[i][j];
            }
        }
    }
    return maximum;
}
int sumOfMatrixElements(int rows, int cols, int **pMatrix){
    int sum = 0;
    for (int i = 1; i < rows; ++i) {
        for (int j = 1; j < cols; ++j) {
            sum += pMatrix[i][j];
        }
    }
    return sum;
}