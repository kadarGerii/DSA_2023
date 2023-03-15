#include "Headers/regular_queue.h"
#include <time.h>

int main() {
    Queue queue1;
    createQueue(10, &queue1);
    srand(time(0));
    for (int i = 0; i < queue1.capacity; i++) {
        int r = rand () %15;
        enqueue(&queue1, r);
    }
    display(queue1);
    dequeue(&queue1);
    printf("\nAfter dequeue:\n");
    display(queue1);
    return 0;
}
