//
// Created by Administrator on 2023-05-03.
//

#ifndef LAB9C_BST_H
#define LAB9C_BST_H
#include <stdlib.h>
#include <stdio.h>
#include <constants.h>
typedef struct Node{
    int info;
    struct Node *left, *right;
}Node;
Node *createNewNode(int newData);
Node *insert(Node *root, int key);
//Node *insertLeft(Node *root, int newData);
//Node *insertRight(Node *root, int newData);
void inorderTraversal(Node *root);
Node *minValueNode(Node *root);
Node *maxValueNode(Node *root);
Node *deleteNode(Node *root, int key);
#endif //LAB9C_BST_H
