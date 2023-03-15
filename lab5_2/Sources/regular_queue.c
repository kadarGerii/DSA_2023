//
// Created by Administrator on 2023-03-15.
//

#include "../Headers/regular_queue.h"
void createQueue(int capacity, Queue *queue){
    queue ->capacity = capacity;
    queue ->front = queue->rear = -1;
    queue ->elements = (int*)calloc(queue->capacity, sizeof(int));
    if (queue -> elements == NULL) {
        printf("%s", MEMORY_ALLOCATION_ERROR_MESSAGE);
        exit(MEMORY_ALLOCATION_ERROR_CODE);
    }
}
void destroyQueue(Queue* queue){
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
void enqueue(Queue* queue, int item){
    if (isFull(*queue)){
        printf(FULL_MESSAGE);
        return;
    }
    if(isEmpty(*queue))
        queue->front = 0;

    queue ->elements[++queue ->rear] = item;
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
    return queue->elements[pos];
}
void display(Queue queue){
    if (isEmpty(queue)) {
        printf(EMPTY_MESSAGE);
        return;
    }
    for (int i = queue.front; i < queue.rear; ++i) {
        printf("%d\n", queue.elements[i]);
    }
}