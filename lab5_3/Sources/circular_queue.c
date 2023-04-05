//
// Created by Administrator on 2023-03-22.
//

#include "../Headers/circular_queue.h"

void createQueue(int capacity, C_Queue *queue){
    queue ->capacity = capacity;
    queue ->front = queue->rear = -1;
    queue ->patients = (char**)calloc(queue->capacity, sizeof(char*));
    if(queue->patients == NULL){
        printf("%s\n", MEMORY_ALLOCATION_ERROR_MESSAGE);
        exit(MEMORY_ALLOCATION_ERROR_CODE);
    }
    for(int i = 0; i < queue->capacity; ++i){
        queue ->patients[i] = (char*)calloc(queue->capacity, sizeof(char));
        if(queue -> patients[i] == NULL){
            printf("%s\n", MEMORY_ALLOCATION_ERROR_MESSAGE);
            exit(MEMORY_ALLOCATION_ERROR_CODE);
        }
    }
    if (queue -> patients == NULL) {
        printf("%s", MEMORY_ALLOCATION_ERROR_MESSAGE);
        exit(MEMORY_ALLOCATION_ERROR_CODE);
    }
}
void destroyQueue(C_Queue * queue){
    for(int i = 0; i < queue->capacity; ++i){
        free(queue -> patients[i]);
    }
    free(queue->patients);
    queue ->front = queue -> rear = -1;
    queue ->capacity = 0;
    queue = NULL;
}
bool isFull(C_Queue queue){
    return queue.front == 0 && queue.rear == queue.capacity-1 || queue.rear == queue.front-1;

}
bool isEmpty(C_Queue queue){
    return queue.front == -1;
}
void enqueue(C_Queue* queue, char* human){
    if(isFull(*queue)) {
        printf(FULL_MESSAGE);
        return;
    }
    if(isEmpty(*queue)) {
        queue->front = 0;
    }
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->patients[queue->rear] = human;

}
char* dequeue(C_Queue* queue){
    if(isEmpty(*queue)) {
        printf(EMPTY_MESSAGE);
        return NULL;
    }
    char *save = queue->patients[queue->front];
    if(queue->front == queue->rear)
    {
        queue->front = queue->rear = -1;
    }
    else {
        queue->front = (queue->front + 1) % queue->capacity;
    }
    return save;
}
void display(C_Queue queue){
    if (isEmpty(queue)) {
        printf("The queue is ");
        printf(EMPTY_MESSAGE);
        return;
    }
    printf("The items of the queue:");
    int i = queue.front;
    do
    {
        printf("%s ", queue.patients[i]);
        i = (i+1) % queue.capacity;
    }while(i != queue.rear);
    printf("%s ", queue.patients[i]);
    printf("\n");
}