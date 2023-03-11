#include "array.h"

int main() {
    IntArray array;
    int value = 1;
    array.capacity = 10;
    createIntArray(array.capacity, &array);
    printArray(array);
    for (int i = 0; i < array.capacity/2; ++i) {
        array.items[i] = value++;
        array.size++;
    }
    printArray(array);
    printf("%d\n", array.size);
    while (!isFull(array)) {
        if(value%2==0)
            insertFirst(&array, value++);
        else
            insertLast(&array, value++);
    }
    printf("%d\n", array.size);
    printArray(array);
    printf("\nCHECK\n");
    int item;
    printf("Number to search:");
    scanf("%d", &item);
    int res = search(&array, item);
    //binaris kereses helyett attertem linearisra, hogy tudjam megoldani a feladat tobbi reszet is
    printf("Position of %d in the array is: %d\n", item, res);
    printf("Number to search:");
    scanf("%d", &item);
    printf("Position of %d in the array is: %d\n", item, search(&array, item));
    printArray(array);
    srand(time(NULL));
    while (!isEmpty(array)) {
        int a = rand() % array.capacity;
        int s = array.size;
        deleteItemAt(&array, a);
        if (array.size < s) {
            printf("Succesfull delete!\n");
        }
        else printf("Not succesfull!\n");
        //printArray(array);
    }
    printArray(array);
    deallocateIntArray(&array);
    return 0;
}
