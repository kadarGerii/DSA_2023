#include "Headers\circular_queue.h"
#include "Headers\patients.h"

int main() {
    int capacity;
    scanf("%d", &capacity);
    C_Queue medicalCenter;
    createQueue(capacity, &medicalCenter);

    return 0;
}
