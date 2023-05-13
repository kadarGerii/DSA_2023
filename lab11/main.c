#include "hash.h"

int main() {
    HashTable table;
    createHashArray(&table);
    insert(&table, 56, 3);
    insert(&table, 45, 12);
    insert(&table, 12, 6);
    insert(&table, 5, 14);
    insert(&table, 58, 5);
    insert(&table, 19, 8);
    insert(&table, 50, 9);
    display(table);
    printf("keresve: %d", search(table, 12));
    delete(&table, 12);
    display(table);
    return 0;
}
