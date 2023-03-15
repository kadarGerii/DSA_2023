//
// Created by Administrator on 2023-03-15.
//

#ifndef LAB5_2_REGULAR_QUEUE_H
#define LAB5_2_REGULAR_QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <constants.h>

typedef struct {
    int capacity;
    int front;
    int rear;
    int *elements;
}Queue;
void createQueue(int capacity, Queue *queue);
void destroyQueue(Queue* queue);
bool isFull(Queue queue);
bool isEmpty(Queue queue);
void enqueue(Queue* queue, int item);
int dequeue(Queue* queue);
void display(Queue queue);
#endif //LAB5_2_REGULAR_QUEUE_H
