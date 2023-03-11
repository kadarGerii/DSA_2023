//
// Created by Administrator on 2023-03-07.
//

#include "array.h"
void createIntArray(int capacity, IntArray* pArray){
    pArray->capacity = capacity;
    pArray->size = 0;
    pArray->items = (int *)calloc(pArray->capacity, sizeof(int));
    if(pArray->items == NULL){
        printf("%s", MEMORY_ALLOCATION_ERROR_MESSAGE);
        exit(MEMORY_ALLOCATION_ERROR_CODE);
    }
}
void printArray(IntArray array){
    if(isEmpty(array)){
        printf("%s\n", ARRAY_IS_EMPTY);
        return;
    }
    for (int i = 0; i < array.size; ++i) {
        printf("%d ", array.items[i]);
    }
    printf("\n");
}
bool isFull(IntArray array){
    if (array.size == array.capacity)
        return true;
    return false;
}
bool isEmpty(IntArray array){
    if (array.size == 0)
        return true;
    return false;
}
int getItemAt(IntArray array, int position){
    if (position >= 0 && position < array.size) {
        return array.items[position];
    }
    else{
        printf("%s\n", INVALID_POSITION);
        return -1;
    }
}
void insertFirst(IntArray* pArray, int item){
    if(isFull(*pArray)){
        printf("%s\n", ARRAY_IS_FULL);
        return;
    }
    for(int i = pArray->size; i > 0; --i){
        pArray->items[i] = pArray->items[i-1];
    }
    pArray -> items[0] = item;
    pArray->size++;
}
void insertLast(IntArray* pArray, int item){
    if(isFull(*pArray)){
        printf("%s\n", ARRAY_IS_FULL);
        return;
    }
    pArray -> items[pArray->size++] = item;
}
void insertAt(IntArray* pArray, int position, int item){
    if(isFull(*pArray)){
        printf("%s\n", ARRAY_IS_FULL);
        return;
    }
    for (int i = position; i > 0; --i) {
        pArray -> items[i] = pArray -> items[i-1];
    }
    pArray -> size++;
    pArray-> items[position] = item;
}
void deleteItemAt(IntArray* pArray, int position){
    if(isEmpty(*pArray)){
        printf("%s\n", ARRAY_IS_EMPTY);
        return;
    }
    if(position >= 0 && position < pArray -> size){
        for (int i = position; i < pArray -> size - 1; ++i) {
            pArray -> items[i] = pArray -> items[i+1];
        }
        pArray -> items[pArray -> size - 1] = 0;
        pArray -> size--;
    }
}
int cmp(const void *a, const void *b){
    int * p = (int *)a;
    int * q = (int *)b;
    if(*p > *q)
        return 1;
    else if(*p < *q)
        return 0;
    else return -1;
}
int search(IntArray *pArray, int item){
    for(int i = 0; i < pArray->capacity; ++i){
        if(pArray -> items[i] == item)
            return i;
    }
    return -1;
}
bool update(IntArray* pArray, int position, int newItem){
    if(position >= 0 && position <= pArray->size){
        pArray->items[position] = newItem;
        return true;
    }
    else{
        printf("%s\n", INVALID_POSITION);
        return false;
    }
}
void deallocateIntArray(IntArray *pArray){
    free(pArray->items);
}