//
// Created by Administrator on 2023-04-20.
//

#include "../../Headers/feladat1.h"
void createQueue(int capacity, Queue *queue){
    queue ->capacity = capacity;
    queue ->front = queue->rear = -1;
    queue ->diakok = (Diak *)calloc(queue->capacity, sizeof(Diak));
    if(queue->diakok == NULL){
        printf("%s\n", MEMORY_ALLOCATION_ERROR_MESSAGE);
        exit(MEMORY_ALLOCATION_ERROR_CODE);
    }
    if (queue -> diakok == NULL) {
        printf("%s", MEMORY_ALLOCATION_ERROR_MESSAGE);
        exit(MEMORY_ALLOCATION_ERROR_CODE);
    }
}
void destroyQueue(Queue* queue){
    free(queue->diakok);
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
bool enqueue(Queue* queue, Diak diak){
    if (isFull(*queue)){
        printf(FULL_MESSAGE);
        printf("\n");
        return false;
    }
    if(queue ->front == -1)
        queue->front = queue -> rear = 0;
    else{
        queue->rear++;
    }
    queue ->diakok[queue -> rear] = diak;
    return true;
}
Diak* dequeue(Queue* queue){
    if(isEmpty(* queue)){
        printf(EMPTY_MESSAGE);
        return NULL;
    }
    int pos = queue ->front;
    if(queue -> front == queue->rear)
        queue->front = queue->rear = -1;
    else{
        queue->front++;
    }
    return &queue->diakok[pos];
}
void display(Queue queue){
    if (isEmpty(queue)) {
        printf(EMPTY_MESSAGE);
        return;
    }
    for (int i = queue.front; i <= queue.rear; ++i) {
        printf("%s - %d\n", queue.diakok[i].name, queue.diakok[i].money);
    }
}

//stack
void createStack(int capacity, Stack * stack){
    stack ->capacity = capacity;
    stack ->top = -1;
    stack ->diakok = (Diak*)calloc(stack->capacity, sizeof(Diak));
}
void destroyStack(Stack* stack){
    stack -> top = -1;
    stack->capacity = 0;
    free(stack->diakok);
    stack = NULL;
}
bool isFulls(Stack stack){
    return stack.top == stack.capacity-1;
}
bool isEmptys(Stack stack){
    return stack.top == -1;
}
void push(Stack* stack, Diak diak){
    if (isFulls(*stack)){
        printf(FULL_MESSAGE);
        return;
    }
    stack -> diakok[++stack->top] = diak;
}
Diak pop(Stack* stack){
    if(isEmptys(*stack)){
        printf(EMPTY_MESSAGE);
        Diak nullDiak = {-1, ""};
        return nullDiak;
    }
    Diak save = stack -> diakok[stack -> top];
    Diak nullDiak = {-1, ""};
    stack ->diakok[stack -> top--] = nullDiak;
    return save;
}
Diak peek(Stack stack){
    if (isEmptys(stack)) {
        printf(EMPTY_MESSAGE);
        Diak nullDiak = {-1, ""};
        return nullDiak;
    }
    return stack.diakok[stack.top];
}
int size(Stack stack){
    return stack.top + 1;
}