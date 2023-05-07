//
// Created by Administrator on 2023-05-03.
//

#include "../Headers/bts_names.h"
Node *createNewNode(Person newData) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf(MEMORY_ALLOCATION_ERROR_MESSAGE);
        exit(MEMORY_ALLOCATION_ERROR_CODE);
    }
    newNode->info = newData;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node *insert(Node *root, Person key) {
    if (root == NULL)
        return createNewNode(key);
    if (strcmp(root->info.name, key.name) == 1)
        root->left = insert(root->left, key);
    else if (strcmp(root->info.name, key.name) == -1)
        root->right = insert(root->right, key);
    else{
        if (root->info.birthdate.year > key.birthdate.year)
            root -> left = insert(root -> left, key);
        else if (root -> info.birthdate.year < key.birthdate.year){
            root->right = insert(root->right, key);
        }
        else{
            if (root -> info.birthdate.month > key.birthdate.month) {
                root -> left = insert(root -> left, key);
            }
            else if (root -> info.birthdate.month < key.birthdate.month){
                root->right = insert(root->right, key);
            }
            else{
                if (root -> info.birthdate.day > key.birthdate.day) {
                    root -> left = insert(root -> left, key);
                } else root->right = insert(root->right, key);
            }
        }
    }
    return root;
}
void inorderTraversal(Node *root) {
    if(root==NULL) return;
    inorderTraversal(root->left);
    printf("%s %d/%d/%d\n",root->info.name, root->info.birthdate.year, root->info.birthdate.month, root->info.birthdate.day);
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

Node *deleteNode(Node *root, Person key) {
    if (root == NULL) return root;
    if (strcmp(key.name, root->info.name) == -1)
        root->left = deleteNode(root->left, key);
    else if (strcmp(key.name, root->info.name) == 1)
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