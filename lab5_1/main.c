#include <string.h>
#include "Headers/stack.h"

int calculateResultByOperation(int val1, int val2, char *token);

int main() {
    char operation[] = "2 5 3 6 + * * 15 / 2 -";
    Stack stack1;
    createStack(strlen(operation), &stack1);
    printf("Stack is %s\n", (isEmpty(stack1))?("EMPTY"):("NOT EMPTY"));
    printf("Stack is %s\n", (isFull(stack1))?("FULL"):("NOT FULL"));
    printf("Size of stack is %i\n", size(stack1));

    const char separators[2] = " ";
    char *token = strtok(operation, separators);
    const char operators[] = "+-*/%";

    while (token != NULL){
        //printf("%s\n", token);
        if(strstr(operators,token)){
            int val1 = pop(&stack1);
            int val2 = pop(&stack1);
            int result = calculateResultByOperation(val2, val1, token);
            push(&stack1, result);
        }
        else {
            int val = atoi(token);
            push(&stack1, val);
        }
        token = strtok(NULL, separators);
    }
    int finalResult = pop(& stack1);
    if(!isEmpty(stack1)){
        printf(INCORRECT_EXPRESSION);
    } else printf("Final result is: %d", finalResult);
    return 0;
}

int calculateResultByOperation(int val1, int val2, char *token) {
    char operation = token[0];
    switch(operation){
        case('+'): return val1+val2;
        case('-'): return val1-val2;
        case('*'): return val1 * val2;
        case('/'): return val1 / val2;
        case('%'): return val1 % val2;
        default : return NULL;
    }
}
