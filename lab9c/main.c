#include "Headers/bst.h"

int main() {
    Node* root = createNewNode(9);
    insert(root, 11);
    insert(root, 8);
    insert(root, 7);
    insert(root, 13);
    insert(root, 19);
    insert(root, 3);
    insert(root, 4);
    insert(root, 2);
    insert(root, 16);
    insert(root, 31);
    inorderTraversal(root);
    return 0;
}
