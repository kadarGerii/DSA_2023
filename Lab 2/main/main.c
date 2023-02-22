#include "functions.h"

int main() {
    int **array;
    int rows, cols;
    allocateMemoryForMatrix2(3,3, &array);
    readMatrix(&rows,&cols, &array, "CON");
    printMatrix(3,3, array, "CON");
    printf("%d\n", minimumValueOfMatrix(3,3,array));
    printf("%0.2f", averageOfMatrixElements(3,3,array));
    deallocateMemoryForMatrix(3,&array);
    return 0;
}
