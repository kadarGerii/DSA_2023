#include "Headers/linked_list.h"

int main() {
    Node *head1 = NULL;
    Node *head2 = NULL;
    int num1, num2;
    printf("Elso szam:");
    scanf("%d", &num1);
    printf("Masodik szam:");
    scanf("%d", &num2);
    while(num1 != 0){
        insertAtEnd(&head1, num1%10);
        num1/=10;
    }
    while(num2 != 0){
        insertAtEnd(&head2, num2%10);
        num2/=10;
    }
    printList(head1);
    printf("\n");
    printList(head2);
    printf("\n");
    Node *head3 = NULL;
    int m = 0;
    int a3 = 0;
    while(head1 != NULL && head2 != NULL) {
        a3 = (head1->data + head2->data + m) % 10;
        m = (m + head1->data + head2->data) / 10;
        insertAtEnd(&head3, a3);
        deleteFromBeginning(&head1);
        deleteFromBeginning(&head2);
    }
    while(head1 != NULL){
        a3 = (head1->data + m) % 10;
        m = (m + head1 -> data) / 10;
        deleteFromBeginning(&head1);
        insertAtEnd(&head3, a3);
    }
    while(head2 != NULL){
        a3 = (head2->data + m) % 10;
        m = (m + head2 -> data)/10;
        deleteFromBeginning(&head2);
        insertAtEnd(&head3, a3);
    }
    if(m != 0)
        insertAtEnd(&head3, m);
    printList(head3);
    head1 = head3;
    int temp = 0;
    while (head1 != NULL) {
        temp = temp * 10 + head1->data;
        head1 = head1->next;
    }
    int result=0;
    while(temp != 0) {
        result = result * 10 + temp % 10;
        temp/=10;
    }
    printf("\nEredmeny: %d\n", result);
    while(head3 != 0){
        insertAtEnd(&head1, head3->data);
        if(head3->data % 2 == 0)
            insertAtEnd(&head1, 0);
        head3 = head3->next;
    }
    printList(head1);
    insertAtEnd(&head1, 1);
    insertAtBeginning(&head1, 1);
    printf("\n");
    printList(head1);
    int key;
    printf("\nkeresett ertek:");
    scanf("%d", &key);
    if(searchNode(head1, key)){
        deleteNode(&head1, key);
    }
    printList(head1);
    printf("\n");
    sortLinkedList(&head1);
    printList(head1);
    return 0;
}
