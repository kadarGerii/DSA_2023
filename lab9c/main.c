#include "Headers/bst.h"

int main() {
    Node* root = createNewNode(13);
    insert(root, 3);
    insert(root, 14);
    insert(root, 1);
    insert(root, 4);
    insert(root, 18);
    insert(root, 2);
    insert(root, 12);
    insert(root, 10);
    insert(root, 5);
    insert(root, 11);
    insert(root, 8);
    insert(root, 7);
    insert(root, 9);
    insert(root, 6);
    inorderTraversal(root);
    return 0;
}
