//
// Created by Administrator on 2023-04-18.
//

#include "../Headers/sorted_list.h"

Node *newNode(int new_data) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    if (!new_node) {
        printf("%s", MEMORY_ALLOCATION_ERROR_MESSAGE);
        exit(MEMORY_ALLOCATION_ERROR_CODE);
    }
    new_node->data = new_data;
    new_node->next = NULL;
    return new_node;
}

bool isEmpty(Node *head) {
    return head == NULL;
}

void insertAtBeginning(Node **head_ref, int new_data) {
    Node *new_node = newNode(new_data);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

void insertAfter(Node *prev_ref, int new_data) {
    if (prev_ref == NULL) {
        printf("NULL_POINTER_EXCEPTION");
        return;
    }
    Node *new_node = newNode(new_data);
    new_node->next = prev_ref->next;
    prev_ref->next = new_node;
}

void insertAtEnd(Node **head_ref, int new_data) {
    Node *last = *head_ref;
    if (isEmpty(*head_ref)) {
        *head_ref = newNode(new_data);
        return;
    }
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = newNode(new_data);
}

void deleteFromBeginning(Node **head_ref) {
    if (isEmpty(*head_ref)) {
        printf("NULL_POINTER_EXCEPTION");
        return;
    }
    Node *temp = *head_ref;
    *head_ref = (*head_ref)->next;
    free(temp);
}

void deleteFromEnd(Node **head_ref) {
    if (isEmpty(*head_ref)) {
        printf("NULL_POINTER_EXCEPTION");
        return;
    }
    Node *last = *head_ref, *prev;
    while (last->next != NULL) {
        prev = last;
        last = last->next;
    }
    prev->next = NULL;
    free(last);
}
void deleteNode(Node** head_ref, int key){
    Node *temp = *head_ref, *prev;
    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) return;
    prev->next = temp->next;
    free(temp);
}
bool searchNode(Node* head_ref, int key){
    Node *current = head_ref;
    while(current != NULL){
        if(current->data == key){
            return true;
        }
        current = current -> next;
    }
    return false;
}
void printList(Node* node) {
    while (node->next != NULL) {
        printf("%4d ", node->data);
        node = node->next;
    }
    printf("%4d ", node->data);
}
int cmp(const void *a, const void *b) {
    int *p = (int*)a;
    int *q = (int*)b;
    if(*p > *q)
        return 1;
    else if (*p < *q)
        return -1;
    else return 0;
}
void sortLinkedList(Node** head_ref){
    int *array = (int *)malloc(size(*head_ref)*sizeof(int));
    int i = 0;
    while(*head_ref != NULL){
        array[i] = (*head_ref)->data;
        ++i;
        *head_ref = (*head_ref)->next;
    }
    int n = i;
    qsort(array, n, sizeof(int), cmp);
    for(i = 0; i < n; ++i){
        insertAtEnd(head_ref,array[i]);
    }
}
int size(Node* head){
    Node *current = head;
    int size = -1;
    while(current != NULL){
        ++size;
        current = current -> next;
    }
    return size;
}
void insert(Node **head, int new_data){
    if(isEmpty(*head)){
        *head = newNode(new_data);
        return;
    }
    if((*head)->data >= new_data){
        insertAtBeginning(head, new_data);
        return;
    }
    Node *last = *head;
    Node *prev = NULL;
    while(last != NULL && last->data <= new_data){
        prev = last;
        last = last -> next;
    }
    Node *temp = newNode(new_data);
    prev->next = temp;
    temp->next = last;
}