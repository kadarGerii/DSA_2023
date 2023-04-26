//
// Created by Administrator on 2023-04-20.
//

#ifndef PLUSZ_FELADAT1_H
#define PLUSZ_FELADAT1_H
#include <stdio.h>
#include <string.h>
#include <constants.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct{
    int money;
    char name[10];
}Diak;
typedef struct {
    int capacity;
    int front;
    int rear;
    Diak *diakok;
}Queue;
void createQueue(int capacity, Queue *queue);
void destroyQueue(Queue* queue);
bool isFull(Queue queue);
bool isEmpty(Queue queue);
bool enqueue(Queue* queue, Diak diak);
Diak* dequeue(Queue* queue);
void display(Queue queue);

//stack
typedef struct{
    int capacity;
    int top;
    Diak *diakok;
}Stack;
void createStack(int capacity, Stack * stack);
void destroyStack(Stack* stack);
bool isFulls(Stack stack);
bool isEmptys(Stack stack);
void push(Stack* stack, Diak diak);
Diak pop(Stack* stack);
Diak peek(Stack stack);
int size(Stack stack);
#endif //PLUSZ_FELADAT1_H
