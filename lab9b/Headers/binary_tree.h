//
// Created by Administrator on 2023-05-03.
//

#ifndef LAB9B_BINARY_TREE_H
#define LAB9B_BINARY_TREE_H
#include <stdlib.h>
#include <stdio.h>
#include <constants.h>
typedef struct Node{
    int info;
    struct Node *left, *right;
}Node;
//create a new node
Node *createNewNode(int newData);
//insert on the left of the node
Node *insertLeft(Node *root, int newData);
//insert on the right of the node
Node *insertRight(Node *root, int newData);
//preorder traversal
void preorderTraversal(Node *root);
//inorder traversal
void inorderTraversal(Node *root);
//postorder traversal
void postorderTraversal(Node *root);
#endif //LAB9B_BINARY_TREE_H
