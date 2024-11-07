#include <stdio.h>

#include "../include/binary_sort_tree.h"

int main(){
    BinSortTree* tree = NULL;
    binSortTreeCtor(&tree, NULL, NULL INIT(tree));

    Node* node = NULL;

    tree->root->data = 50;

    createNode(&node, 20);
    tree->root->left = node;
    createNode(&node, 70);
    tree->root->right = node;
    createNode(&node, 60);
    tree->root->right->left = node;
    createNode(&node, 80);
    tree->root->right->right = node;
    createNode(&node, 55);
    tree->root->right->left->left = node;
    createNode(&node, 75);
    tree->root->right->right->left = node;

    printBinSortTree(tree, PREFIX);
    printBinSortTree(tree, POSTFIX);
    printBinSortTree(tree, INFIX);
}
