//
// Created by Administrator on 2023-03-07.
//

#ifndef LAB4_ARRAY_H
#define LAB4_ARRAY_H
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <constants.h>
#include <time.h>

typedef struct {
    int capacity;
    int size;
    int *items;
}IntArray;
void createIntArray(int capacity, IntArray* pArray);
void printArray(IntArray array);
bool isFull(IntArray array);
bool isEmpty(IntArray array);
int getItemAt(IntArray array, int position);
void insertFirst(IntArray* pArray, int item);
void insertLast(IntArray* pArray, int item);
void insertAt(IntArray* pArray, int position, int item);
void deleteItemAt(IntArray* pArray, int position);
int cmp(const void* a, const void* b);
int *search(IntArray *pArray, int item);
bool update(IntArray* pArray, int position, int newItem);
void deallocateIntArray(IntArray *pArray);
#endif //LAB4_ARRAY_H
