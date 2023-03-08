#include "array.h"

int main() {
    IntArray array;
    array.capacity = 10;
    createIntArray(array.capacity, &array);
    printArray(array);
    for (int i = 0; i < array.capacity/2; ++i) {
        array.items[i] = i + 1;
        array.size++;
    }
    printArray(array);
    printf("%d\n", array.size);
    int i = array.capacity / 2 + 1;
    /*while (!isFull(array)) {
        if(i%2==0)
            insertFirst(&array, i);
        else
            insertLast(&array, i);
        i++;
    }*/
    printf("%d\n", array.size);
    printArray(array);
    printf("\nCHECK\n");
    srand(time(NULL));
    while (!isEmpty(array)) {
        int a = rand() % array.capacity;
        deleteItemAt(&array, a);
    }
    printArray(array);
    deallocateIntArray(&array);
    return 0;
}
