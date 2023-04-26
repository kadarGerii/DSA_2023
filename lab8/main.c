#include "Headers/linked_list.h"

int main() {
    Node *head1 = NULL;
    Node *head2 = NULL;
    int num1, num2;
    printf("Elso szam: ");
    scanf("%d", &num1);
    printf("Masodik szam: ");
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
    return 0;
}
