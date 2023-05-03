//
// Created by Administrator on 2023-05-03.
//

#include "../Headers/bst.h"
Node *createNewNode(int newData) {
    Node *newNode = malloc(sizeof(Node));
    if (!newNode) {
        printf(MEMORY_ALLOCATION_ERROR_MESSAGE);
        exit(MEMORY_ALLOCATION_ERROR_CODE);
    }
    newNode->info = newData;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}