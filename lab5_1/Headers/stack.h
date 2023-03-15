//
// Created by Administrator on 2023-03-15.
//

#ifndef LAB5_1_STACK_H
#define LAB5_1_STACK_H

#include <stdio.h>
#include <constants.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct{
    int capacity;
    int top;
    int *elemets;
}Stack;
void createStack(int capacity, Stack * stack);
void destroyStack(Stack* stack);
bool isFull(Stack stack);
bool isEmpty(Stack stack);
void push(Stack* stack, int item);
int pop(Stack* stack);
int peek(Stack stack);
int size(Stack stack);
#endif //LAB5_1_STACK_H
