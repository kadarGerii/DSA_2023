//
// Created by Administrator on 2023-05-10.
//

#include "hash.h"

void createHashArray(HashTable *pHashTable) {
    pHashTable->items = (HashItem *)calloc(CAPACITY, sizeof(HashItem));
    if(!pHashTable->items){
        printf("%s", MEMORY_ALLOCATION_ERROR_MESSAGE);
        exit(MEMORY_ALLOCATION_ERROR_CODE);
    }
    pHashTable->size = 0;

    for(int i = 0; i < CAPACITY; ++i){
        pHashTable->items[i] = dummyData;
    }

}
int hashCode(int key) {
    return key % CAPACITY;
}
void insert(HashTable *hashTable, int key, int data) {
    //ha van hely, meg kell nezni
    int index = hashCode(key);
    int i = 0;
    while(hashTable->items[(index + i) % CAPACITY].key != dummyData.key){
        i++;
    }
    HashItem item = {key, data};
    hashTable->items[(index + i) % CAPACITY] = item;
    hashTable->size++;
    display(*hashTable);
}

void display(HashTable hashTable) {
    printf("hashTable:\n");
    if(hashTable.size == 0) return;
    printf("\tpos\t:\tkey\tvalue    ->    mod\n");
    for(int i = 0; i < CAPACITY; ++i){
        if(hashTable.items[i].key != -1){
            printf("\t%i\t:\t%i\t%i\t ->\t%i\n", i, hashTable.items[i].key, hashTable.items[i].data, hashCode(hashTable.items[i].key));
        }
    }
}

int search(HashTable hashTable, int key) {
    int index = hashCode(key);
    HashItem *item = &hashTable.items[index];
    if(item != NULL){
        if(item->key == key)
            return item->data;
    }
    return dummyData.data;
}

void delete(HashTable *hashTable, int key) {
    int index = hashCode(key);
    if(search(*hashTable, key) != dummyData.data){
        hashTable->items[index].key = dummyData.key;
        hashTable -> items[index].data = dummyData.data;
    }
}

void destroyHashArray(HashTable *pHashTable) {
    free(pHashTable);
}
