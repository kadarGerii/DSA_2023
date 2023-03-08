#include "array.h"

int main() {
    IntArray array;
    printf("Read capacity:");
    scanf("%d", &array.capacity);
    printf("Read size:");
    scanf("%d", &array.size);
    createIntArray(array.capacity, &array);
    srand(time(NULL));
    for (int i = 0; i < array.size; ++i) {
        array.items[i] = rand() % 10;
    }
    printArray(array);
    int a = search(array, 2);
    printf("%d", a);
    /*printf("Get iteam at pos: %d\n", getItemAt(array, 3));
    insertFirst(&array, 2);
    printArray(array);
    insertLast(&array, 2);
    printArray(array);
    insertAt(&array, 2, 3);
    printArray(array);
    deleteItemAt(&array,3);
    printArray(array);*/
    return 0;
}
