//
// Created by Administrator on 2023-02-21.
//

#ifndef HAZI2_FUNCTIONS_H
#define HAZI2_FUNCTIONS_H
#include <stdio.h>
#include <malloc.h>
#include <time.h>

float average(int n, int *pArray);
int numberOfOddNumbers(int n, int *pArray);
int productOfNegativeNumbers(int n, int *pArray);
int maximumValueOfColumn(int rows, int columnIndex, int **pMatrix);
int* columnMaximums(int rows, int cols, int **pMatrix);
int maximumValueOfMatrix(int rows, int cols, int **pMatrix);
int sumOfMatrixElements(int rows, int cols, int **pMatrix);
#endif //HAZI2_FUNCTIONS_H