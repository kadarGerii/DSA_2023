//
// Created by Administrator on 2023-05-03.
//

#ifndef LAB9D_BTS_NAMES_H
#define LAB9D_BTS_NAMES_H
#include <stdlib.h>
#include <stdio.h>
#include <constants.h>
#include <string.h>
#include <stdbool.h>
typedef struct{
    int year, month, day;
}MyDate;
typedef struct{
    char name[10];
    MyDate birthdate;
    bool gender;
}Person;
typedef struct Node{
    Person info;
    struct Node *left, *right;
}Node;
Node *createNewNode(Person newData);
Node *insert(Node *root, Person key);
//Node *insertLeft(Node *root, int newData);
//Node *insertRight(Node *root, int newData);
void inorderTraversal(Node *root);
Node *minValueNode(Node *root);
Node *maxValueNode(Node *root);
Node *deleteNode(Node *root, Person key);
#endif //LAB9D_BTS_NAMES_H
