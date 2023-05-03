#include "Headers/sorted_list.h"
void createNumbers(int n);
int main() {
    createNumbers(-346853246);
    return 0;
}
void createNumbers(int n){
    Node *head1 = NULL;
    while(n != 0){
        insert(&head1, n%10);
        n/=10;
    }
    printList(head1);
    printf("\n");
}