//
// Created by Administrator on 2023-02-22.
//

#ifndef MAIN_FUNCTIONS_H
#define MAIN_FUNCTIONS_H
#include <stdio.h>
int numberOfEvenNumbers(int n, int *pArray);
int sumOfPositiveNumbers(int n, int *pArray);
void allocateMemoryForMatrix2(int rows, int cols, int ***dpMatrix);
void readMatrix(int *pRows, int *pCols, int ***dpArray, const char *input);
void printMatrix(int rows, int cols, int **pMatrix, const char *output);
int minimumValueOfRow(int cols, int *pRow);
int* rowMinimums(int rows, int cols, int **pMatrix);
int minimumValueOfMatrix(int rows, int cols, int **pMatrix);
float averageOfMatrixElements(int rows, int cols, int **pMatrix);
void deallocateMemoryForMatrix(int rows, int ***dpMatrix);
#endif //MAIN_FUNCTIONS_H
