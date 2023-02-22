//
// Created by Administrator on 2023-02-22.
//

#include <malloc.h>
#include <time.h>
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
    if(*dpMatrix == NULL){
        printf("Error allocating memory");
        exit(1);
    }
    for (int i = 0; i < rows; ++i) {
        (*dpMatrix)[i] = (int*)malloc(cols * sizeof(int));
        if((*dpMatrix)[i] == NULL){
            printf("Error allocating memory!");
            exit(1);
        }
    }
}
void readMatrix(int *pRows, int *pCols, int ***dpArray, const char *input){
    if(!freopen(input,"r", stdin)){
        printf("Error opening file");
        exit(2);
    }
    scanf("%d%d", pRows, pCols);
    for (int i = 0; i < *pRows; ++i) {
        for(int j = 0; j < *pCols; ++j){
            scanf("%d", &(*dpArray)[i][j]);
        }
    }
    freopen("CON", "r", stdin);
}
void printMatrix(int rows, int cols, int **pMatrix, const char *output){
    if(!freopen(output,"w",stdout)){
        printf("Error file opening");
        exit(2);
    }
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("%d ", pMatrix[i][j]);
        }
        printf("\n");
    }
    freopen("CON", "w", stdout);
}
int minimumValueOfRow(int cols, int *pRow){
    int minimum = pRow[0];
    for (int i = 1; i < cols; ++i) {
        if(pRow[i] < minimum) minimum = pRow[i];
    }
    return minimum;
}
int* rowMinimums(int rows, int cols, int **pMatrix){
    int *minimum = (int*)malloc(rows * sizeof(int));
    if (minimum == NULL) {
        printf("Error allocating memory");
        exit(1);
    }
    int minValue;
    for (int i = 0; i < rows; ++i){
        minimum[i] = minimumValueOfRow(cols, pMatrix[i]);
    }
    return minimum;
}
int minimumValueOfMatrix(int rows, int cols, int **pMatrix){
    int *minim = rowMinimums(rows, cols, pMatrix);
    int minimum = minimumValueOfRow(cols, minim);
    return minimum;
}
float averageOfMatrixElements(int rows, int cols, int **pMatrix){
    int sum = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            sum += pMatrix[i][j];
        }
    }
    return (float)sum/(rows*cols);
}
void deallocateMemoryForMatrix(int rows, int ***dpMatrix){
    for(int i = 0; i < rows; ++i){
        free((*dpMatrix)[i]);
    }
    free(*dpMatrix);
}