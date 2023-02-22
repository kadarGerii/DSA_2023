#include "Functions.h"

int main() {
    int b[]={1,2,32,4,57,6,7,8,9,29,42};
    printf("Average: %0.2f", average(11, b));
    printf("Odd: %d\n", numberOfOddNumbers(11,b));
    printf("Negative: %d", productOfNegativeNumbers(11,b));

    srand(time(NULL));
    int **a = (int**)malloc(3*sizeof(int*));
    for (int i = 0; i < 3; i++) {
        a[i] = (int*)malloc(3*sizeof(int));
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            a[i][j] = rand()%10;
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    int *solution = columnMaximums(3, 3, a);
    for (int i = 0; i < 3; i++) {
        printf("%i ", solution[i]);
    }
    free(solution);

    printf("Max Matrix: %d", maximumValueOfMatrix(3, 3, a));
    printf("Matrix elements: %d", sumOfMatrixElements(3, 3, a));

    for (int i = 0; i < 3; i++) {
        free(a[i]);
    }
    free(a);
    return 0;
}
