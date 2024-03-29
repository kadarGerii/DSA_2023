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

Node *insert(Node *root, int key) {
    if (root == NULL)
        return createNewNode(key);
    if (key < root->info)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);
    return root;
}
void inorderTraversal(Node *root) {
    if(root==NULL) return;
    inorderTraversal(root->left);
    printf("%i ",root->info);
    inorderTraversal(root->right);
}
Node *minValueNode(Node *root) {
    Node *current = root;
    while (current != NULL && current->left != NULL)
        current = current->left;
    return current;
}

Node *maxValueNode(Node *root) {
    Node *current = root;
    while (current != NULL && current->right != NULL)
        current = current->right;
    return current;
}

Node *deleteNode(Node *root, int key) {
    if (root == NULL) return root;
    if (key < root->info)
        root->left = deleteNode(root->left, key);
    else if (key > root->info)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL) {
            Node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node *temp = root->left;
            free(root);
            return (temp);
        }
        Node *temp = minValueNode(root->right);
        root->info = temp->info;
        root->right = deleteNode(root->right, temp->info);
    }
    return root;
}