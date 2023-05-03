

#include "Headers/binary_tree.h"

int main() {
    Node *tree = createNewNode(1);
    insertLeft(tree, 2);
    insertRight(tree, 3);
    insertLeft(tree->left,4);
    insertRight(tree->left, 5);
    insertLeft(tree->right,6);
    insertRight(tree->right,7);
    preorderTraversal(tree);
    printf("\n");
    inorderTraversal(tree);
    printf("\n");
    postorderTraversal(tree);
    return 0;
}
