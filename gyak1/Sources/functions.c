//
// Created by Administrator on 2023-02-15.
//

#include "functions.h"
#include "constants.h"

int sum(int x, int y){
    return x+y;
}
float minimum(float x, float y, float z){
    if(x < y && x < z) return x;
    if(x > y && y < z) return y;
    if(z < y && x > z) return z;
}
int* allocateMemoryForArray1(int n){
    int* pArray = (int*)malloc(n*sizeof(int));
    if(pArray == NULL){
        printf(MEMORY_ALLOCATION_ERROR_MESSAGE);
        exit(MEMORY_ALLOCATION_ERROR_CODE);
    }
    return pArray;
}
void allocateMemoryForArray2(int n, int** dpArray){
    *dpArray = (int*)malloc(n*sizeof(int));
    if(*dpArray == NULL){
        printf(MEMORY_ALLOCATION_ERROR_MESSAGE);
        exit(MEMORY_ALLOCATION_ERROR_CODE);
    }
}
void readArray(int *n, int **dpArray, const char *input){
    if(!freopen(input, "r", stdin)){
        printf(FILE_OPENING_ERROR_MESSAGE);
        exit(FILE_OPENING_ERROR_CODE);
    }
    scanf("%d", n);
    allocateMemoryForArray2(*n, dpArray);
    for (int i = 0; i < *n; ++i) {
        scanf("%d", &((*dpArray)[i]));//*dpArray + i;
    }
    freopen("CON", "r", stdin);
}
void printArray(int n, int *pArray, const char *output){
    freopen(output, "w", stdout);
    for(int i = 0; i < n; ++i){
        printf("%i ", pArray[i]);
    }
    freopen("CON", "w", stdout);
}
void deallocateMemoryForArray(int **dpArray){
    free(*dpArray);
    *dpArray = NULL;
}
float avg(float number1, float number2){
    return (float)(number1+number2)/2;
}
float maximum(float x, float y, float z){
    if(x > y && x > z) return x;
    if(x < y && y > z) return y;
    if(z > y && x < z) return z;
}
void fillWithRandomNumbers(int n, int *pArray, int start, int end){
    srand(time(NULL));
    for (int i = 0; i < n; ++i) {
        pArray[i] = (rand() % (end - start + 1)) + start;
    }
}
void printArrayInReverseOrder(int n, int *pArray, const char* input){
    freopen(input, "w", stdout);
    for(int i = n-1; i >= 0; --i){
        printf("%i ", pArray[i]);
    }
    freopen("CON", "w", stdout);
}
