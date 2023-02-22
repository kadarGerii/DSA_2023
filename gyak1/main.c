#include "functions.h"

int main() {
    printf("%d\n", sum(4,7));
    printf("Harom szam kozul a legnagyobb: %.2f\n", minimum(1.4,4.6,7.5));
    int n, *array;
    readArray(&n, &array, "CON");
    printArray(n, array, "CON");
    deallocateMemoryForArray(&array);
    return 0;
}