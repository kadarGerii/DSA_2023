//
// Created by Administrator on 2023-03-07.
//

#include "array.h"
void createIntArray(int capacity, IntArray* pArray){
    pArray->items = (int *)calloc(capacity, sizeof(int));
    if(pArray->items == NULL){
        printf("%s", MEMORY_ALLOCATION_ERROR_MESSAGE);
        exit(MEMORY_ALLOCATION_ERROR_CODE);
    }
}
void printArray(IntArray array){
    for (int i = 0; i < array.capacity; i++) {
        printf("%d ", array.items[i]);
    }
    printf("\n");
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
    else{
        printf("%s\n", INVALID_POSITION);
        return -1;
    }
}
void insertFirst(IntArray* pArray, int item){
    if(isFull(*pArray) == false){
        for(int i = pArray->size; i >= 0; --i){
            pArray->items[i+1] = pArray->items[i];
        }
        pArray->size++;
        pArray -> items[0] = item;
    }
    else{
        printf("%s\n", ARRAY_IS_FULL);
    }
}
void insertLast(IntArray* pArray, int item){
    if(isFull(*pArray) == false){
        pArray -> items[pArray->size] = item;
        pArray->size++;
    }
    else{
        printf("%s\n", ARRAY_IS_FULL);
    }
}
void insertAt(IntArray* pArray, int position, int item){
    if(isFull(*pArray) == false){
        for (int i = pArray -> size; i >= 0; --i) {
            pArray -> items[i+1] = pArray -> items[i];
        }
        pArray -> size++;
        pArray-> items[position] = item;
    }
    else{
        printf("%s\n", ARRAY_IS_FULL);
    }
}
void deleteItemAt(IntArray* pArray, int position){
    if(isEmpty(*pArray) == false){
        for (int i = position; i < pArray -> size; ++i) {
            pArray -> items[i] = pArray -> items[i+1];
        }
        pArray -> size--;
    }
    else{
        printf("%s\n", ARRAY_IS_EMPTY);
    }
}
int cmp(const void *a, const void *b){
    int * p = (int *)a;
    int * q = (int *)b;
    if(p > q)
        return 1;
    else if(p < q)
        return 0;
    else return -1;
}
int search(IntArray pArray, int item){
    qsort(pArray.items, pArray.size, sizeof(int), cmp);
    int* result =(int*) bsearch(&item, pArray.items, pArray.size, sizeof(int), cmp);
    if (result == NULL) {
        return -1;
    }
    return *result;
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