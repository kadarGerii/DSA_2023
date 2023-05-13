//
// Created by Administrator on 2023-05-10.
//

#ifndef LAB11_HASH_H
#define LAB11_HASH_H
#define CAPACITY 31
#include <stdlib.h>
#include <stdio.h>
#include <constants.h>
typedef struct {
    int key;
    int data;
} HashItem;
typedef struct {
    HashItem *items;
    int size;
}HashTable;
static HashItem dummyData = {-1, 0};
/**
* Allocates memory for a hash table with defined SIZE
* @param pHashTable
*/
void createHashArray(HashTable *pHashTable);
//This should be only accessible in the .c file
//int hashCode(int key);
/**
* Inserts a new data to the hashArray
* @param hashTable
* @param key
* @param data
*/
void insert(HashTable *hashTable, int key, int data);
/**
* Deletes a data from the array
* @param hashTable
* @param key
2
* @param data
*/
void delete(HashTable *hashTable, int key);
/**
* Searches for a specific data with the given key
* @param hashTable
* @param key
* @return the position if it is present, -1 otherwise
*/
int search(HashTable hashTable, int key);
/**
* Prints the content of the array to the standard input
* @param hashTable
*/
void display(HashTable hashTable);
/**
* Returns the number of elements present in the hashtable
* @param hashTable
* @return size
*/
int size(HashTable hashTable);
/**
* Deallocates memory
* @param pHashTable
*/
void destroyHashArray(HashTable *pHashTable);
#endif //LAB11_HASH_H
