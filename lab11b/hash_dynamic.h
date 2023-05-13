//
// Created by Administrator on 2023-05-10.
//

#ifndef LAB11B_HASH_DYNAMIC_H
#define LAB11B_HASH_DYNAMIC_H
#define CAPACITY 13
typedef struct {
   // Node *items[CAPACITY];
}HashTable;
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
void insert(HashTable *hashTable, char* key, char* data);
/**
* Deletes a data from the array
* @param hashTable
* @param key
* @param data
*/
void delete(HashTable *hashTable, char *key);
/**
* Searches for a specific data with the given key
* @param hashTable
* @param key
* @return the position if it is present, -1 otherwise
*/
bool search(HashTable hashTable, char* key);
/**
* Prints the content of the array to the standard input
* @param hashTable
*/
void display(HashTable hashTable);
/**
* Deallocates memory
* @param pHashTable
*/
void destroyHashArray(HashTable *pHashTable);

typedef struct {
    char key[20];
    char data[50];
} HashItem;
typedef struct Node {
    HashItem data;
    struct Node *next;
} Node;
/**
* Allocates memory for a new node
* @param new_data
* @return pointer to a new allocated node
*/
Node* newNode(HashItem new_data);
/**
* Checks if list is empty, head is NULL pointer
* @param head
* @return true/false
*/
bool isEmpty(Node *head);
/**
* Insert new node at start of the list
* @param head_ref
* @param new_data
*/
void insertFirst(Node **head_ref, HashItem new_data);
/**
* Delete a specific node
* @param head_ref
* @param key
*/
bool deleteNode(Node** head_ref, char *key);
/**
* Searches for a specific node with value key
* @param head_ref
* @param key
* @return
*/
bool searchNode(Node* head_ref, char *key);
/**
* Print all elements of teh list
* @param node
*/
void printList(Node* node);
/**
* Prints the data of the node
* @param item
*/
void printItem(HashItem item);
/**
* Deallocates memory
* @param head
*/
void freeList(Node **head);
#endif //LAB11B_HASH_DYNAMIC_H
