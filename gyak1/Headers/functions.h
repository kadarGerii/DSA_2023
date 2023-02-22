//
// Created by Administrator on 2023-02-15.
//

#ifndef GYAK1_FUNCTIONS_H
#define GYAK1_FUNCTIONS_H
int sum(int x, int y);
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
float minimum(float x, float y, float z);
int* allocateMemoryForArray1(int n);
void allocateMemoryForArray2(int n, int** dpArray);
void readArray(int *n, int **dpArray, const char *input);
void printArray(int n, int *pArray, const char *output);
void deallocateMemoryForArray(int **dpArray);
float avg(float number1, float number2);
float maximum(float number1, float number2, float number3);
void fillWithRandomNumbers(int n, int *pArray, int start, int end);

#endif //GYAK1_FUNCTIONS_H
