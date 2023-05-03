//
// Created by Administrator on 2023-05-03.
//

#include "../Headers/binary_tree.h"

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

Node *insertLeft(Node *root, int newData) {
    root->left = createNewNode(newData);
    return root->left;
}

Node *insertRight(Node *root, int newData) {
    root->right = createNewNode(newData);
    return root->right;
}

void preorderTraversal(Node *root) {
    if (root == NULL) return;
    printf("%d ", root->info);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void inorderTraversal(Node *root) {
    if (root == NULL) return;
    inorderTraversal(root->left);
    printf("%i ", root->info);
    inorderTraversal(root->right);
}

void postorderTraversal(Node *root) {
    if (root == NULL) return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%i ", root->info);
}
