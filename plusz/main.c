#include "Headers/feladat1.h"

int main() {
    Queue q1;
    int m;
    printf("Ennyit tud kiszolgalni:");
    scanf("%d",&m);
    if(!freopen("bufe.txt", "r", stdin)){
        printf("Failed to open");
        return -1;
    }
    int n;
    scanf("%d",&n);
    Diak *diak = (Diak *) malloc(n*sizeof(Diak));
    if (diak == NULL) {
        printf("%s", MEMORY_ALLOCATION_ERROR_MESSAGE);
        exit(MEMORY_ALLOCATION_ERROR_CODE);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%s\n", diak[i].name);
        scanf("%d", &diak[i].money);
    }
    createQueue(m,&q1);
    freopen("CON", "r", stdin);
    int sikeres=0, sikertelen = 0;
    float profit = 0;
    for (int i = 0; i < n; ++i) {
        if(enqueue(&q1, diak[i])){
            sikeres++;
            profit += (float)diak[i].money / 2;
        }
        else sikertelen++;
    }
    printf("A kovetkezo diakok kerultek sorra: ");
    for(int i = 0; i < sikeres; ++i){
        printf("%s ", diak[i].name);
    }
    printf("\n");
    printf("Ennyit keresett a bufes neni: %0.2f\n", profit);
    Stack stack;
    int counter = sikeres, osszeg=0;
    createStack(n, &stack);
    for (int i = sikeres; i < sikertelen; ++i) {
        push(&stack, diak[i]);
        osszeg += counter;
        diak[i].money += counter++;
    }
    int k;
    printf("Ennyi szunet:");
    scanf("%d", &k);
    profit *= k;
    sikeres *= k;
    sikertelen *= k;
    osszeg *= k;
    int nyereseg = profit - osszeg;
    printf("A bufes neni nyeresege a nap vegen: %d", nyereseg);
    return 0;
}
