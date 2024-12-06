#include <stdio.h>

#include "../include/binary_sort_tree.h"
#include "../include/bin_sort_tree_dump.h"

int main(){
    BinSortTree* tree = NULL;
    binSortTreeCtor(&tree, NULL, NULL INIT(tree));

    Node* node = NULL;

    tree->root->data = 50;

    // createNode(&node, 20);
    // tree->root->left = node;
    // createNode(&node, 70);
    // tree->root->right = node;
    // createNode(&node, 60);
    // tree->root->right->left = node;
    // createNode(&node, 80);
    // tree->root->right->right = node;
    // createNode(&node, 55);
    // tree->root->right->left->left = node;
    // createNode(&node, 75);
    // tree->root->right->right->left = node;
    binSortTreePush(tree, 20);
    binSortTreePush(tree, 70);
    binSortTreePush(tree, 60);
    binSortTreePush(tree, 80);
    binSortTreePush(tree, 55);
    binSortTreePush(tree, 75);
    binSortTreePush(tree, 61);
    binSortTreePush(tree, 61);

    binSortTreeDump(DUMP(tree), 0);

    printBinSortTree(tree, PREFIX);
    printBinSortTree(tree, POSTFIX);
    printBinSortTree(tree, INFIX);

    binSortTreeDtor(&tree);
}
