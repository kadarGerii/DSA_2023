#include "Headers/regular_queue.h"
#include <time.h>

int main() {
    Queue queue;
    createQueue(5, &queue);
    int x;
    while(1){
        int option;
        printf("\nChoose from the following:"
               "\n\t- 1. isFull?"
               "\n\t- 2. isEmpty?"
               "\n\t- 3. New car arrive (enqueue)"
               "\n\t- 4. Remove car (dequeue)"
               "\n\t- 5. Display all data"
               "\n\t- 0. Exit");
        printf("\nYour option:");
        scanf("%d", &option);
        switch (option) {
            case 0:
                printf("Exit...");
                return 0;
            case 1 :
                printf("The queue is %s", (isFull(queue) ? "FULL" : "NOT FULL"));
                break;
            case 2 :
                printf("The queue is %s", (isEmpty(queue) ? "EMPTY" : "NOT EMPTY"));
                break;
            case 3 :
                scanf("%d", &x);
                enqueue(&queue, x);
                break;
            case 4 :
                dequeue(&queue);
                break;
            case 5 :
                display(queue);
                break;


        }
    }
    return 0;
}
