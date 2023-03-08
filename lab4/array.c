//
// Created by Administrator on 2023-03-07.
//

#include "array.h"
void createIntArray(int capacity, IntArray* pArray){
    pArray = (IntArray*)malloc(capacity * sizeof(IntArray));
    if(pArray == NULL){
        printf("%s", MEMORY_ALLOCATION_ERROR_MESSAGE);
        exit(MEMORY_ALLOCATION_ERROR_CODE);
    }
}
void printArray(IntArray array){
    for (int i = 0; i < array.capacity; i++) {
        printf("%d\n", array.capacity);
        printf("%d\n", array.size);
        printf("%d\n", *array.items);
    }
}
bool isFull(IntArray array){
    if (array.capacity == array.size)
        return true;
    return false;
}
bool isEmpty(IntArray array){
    if (0 == array.size)
        return true;
    return false;
}
int getItemAt(IntArray array, int position){
    if (position >= 0 && position < array.size) {
        return array.items[position];
    }
    return -1;
}
void insertFirst(IntArray* pArray, int item){

}