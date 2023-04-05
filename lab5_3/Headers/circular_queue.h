//
// Created by Administrator on 2023-03-22.
//

#ifndef LAB5_3_CIRCULAR_QUEUE_H
#define LAB5_3_CIRCULAR_QUEUE_H
#include <stdio.h>
#include <string.h>
#include <constants.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
    int capacity;
    int front;
    int rear;
    char **patients;
}C_Queue;
void createQueue(int capacity, C_Queue *queue);
void destroyQueue(C_Queue * queue);
bool isFull(C_Queue queue);
bool isEmpty(C_Queue queue);
void enqueue(C_Queue* queue, char* item);
char* dequeue(C_Queue* queue);
void display(C_Queue queue);
#endif //LAB5_3_CIRCULAR_QUEUE_H
