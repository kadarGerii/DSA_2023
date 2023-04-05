//
// Created by Administrator on 2023-03-15.
//

#include <string.h>
#include "../Headers/regular_queue.h"
void createQueue(int capacity, Queue *queue){
    queue ->capacity = capacity;
    queue ->front = queue->rear = -1;
    queue ->elements = (char**)calloc(queue->capacity, sizeof(char*));
    if(queue->elements == NULL){
        printf("%s\n", MEMORY_ALLOCATION_ERROR_MESSAGE);
        exit(MEMORY_ALLOCATION_ERROR_CODE);
    }
    for(int i = 0; i < queue->capacity; ++i){
        queue ->elements[i] = (char*)calloc(queue->capacity, sizeof(char));
        if(queue -> elements[i] == NULL){
            printf("%s\n", MEMORY_ALLOCATION_ERROR_MESSAGE);
            exit(MEMORY_ALLOCATION_ERROR_CODE);
        }
    }
    if (queue -> elements == NULL) {
        printf("%s", MEMORY_ALLOCATION_ERROR_MESSAGE);
        exit(MEMORY_ALLOCATION_ERROR_CODE);
    }
}
void destroyQueue(Queue* queue){
    for(int i = 0; i < queue->capacity; ++i){
        free(queue -> elements[i]);
    }
    free(queue->elements);
    queue ->front = queue -> rear = -1;
    queue ->capacity = 0;
    queue = NULL;
}
bool isFull(Queue queue){
    return queue.rear == queue.capacity-1;
}
bool isEmpty(Queue queue){
    return queue.front == -1;
}
void enqueue(Queue* queue, char* item){
    if (isFull(*queue)){
        printf(FULL_MESSAGE);
        return;
    }
    if(queue ->front == -1)
        queue->front = queue -> rear = 0;
    else{
        queue->rear++;
    }
    strcpy(queue ->elements[queue -> rear],item);
}
int dequeue(Queue* queue){
    if(isEmpty(* queue)){
        printf(EMPTY_MESSAGE);
        return -1;
    }
    int pos = queue ->front;
    if(queue -> front == queue->rear)
        queue->front = queue->rear = -1;
    else{
        queue->front++;
    }
    return queue->elements[queue->front][pos];
}
void display(Queue queue){
    if (isEmpty(queue)) {
        printf(EMPTY_MESSAGE);
        return;
    }
    for (int i = queue.front; i <= queue.rear; ++i) {
        printf("%s\n", queue.elements[i]);
    }
}