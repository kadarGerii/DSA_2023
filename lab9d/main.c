#include "Headers/bts_names.h"

int main() {
    //Beszuras nevek alapjan
    //ha ket nev egyforma akkor szuletesi datum szerint
    //gender szerint nem merem
    Person person1 = {"Akos", 2003, 10, 10, 1};
    Person person2 = {"Akos", 2003, 10, 11, 1};
    Person person3 = {"Akos", 2003, 10, 9, 1};
    Person person4 = {"Akos", 2003, 10, 7, 0};
    Node *root = createNewNode(person1);
    insert(root, person2);
    insert(root, person3);
    insert(root, person4);
    inorderTraversal(root);
    return 0;
}
