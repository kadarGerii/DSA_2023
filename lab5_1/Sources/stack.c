//
// Created by Administrator on 2023-03-15.
//

#include "../Headers/stack.h"

void createStack(int capacity, Stack * stack){
    stack ->capacity = capacity;
    stack ->top = -1;
    stack ->elemets = (int*)calloc(stack->capacity, sizeof(int));
}
void destroyStack(Stack* stack){
    stack -> top = -1;
    stack->capacity = 0;
    free(stack->elemets);
    stack = NULL;
}
bool isFull(Stack stack){
    return stack.top == stack.capacity-1;
}
bool isEmpty(Stack stack){
    return stack.top == -1;
}
void push(Stack* stack, int item){
    if (isFull(*stack)){
        printf(FULL_MESSAGE);
        return;
    }
    stack -> elemets[++stack->top] = item;
}
int pop(Stack* stack){
    if(isEmpty(*stack)){
        printf(EMPTY_MESSAGE);
        return INT_MIN;
    }
    int save = stack -> elemets[stack -> top];
    stack ->elemets[stack -> top--] = 0;
    return save;
}
int peek(Stack stack){
    if (isEmpty(stack)) {
        printf(EMPTY_MESSAGE);
        return INT_MIN;
    }
    return stack.elemets[stack.top];
}
int size(Stack stack){
    return stack.top + 1;
}