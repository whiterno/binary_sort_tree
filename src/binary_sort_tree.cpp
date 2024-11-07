#include <stdio.h>
#include <stdlib.h>

#include "../include/binary_sort_tree.h"

static int binSortTreeVerify(BinSortTree** tree);
static void printNodePostfix(Node* node);
static void printNodePrefix(Node* node);
static void printNodeInfix(Node* node);

int binSortTreeCtor(BinSortTree** tree, BinSortTree* left_tree, BinSortTree* right_tree INIT_ARGS){
    if (tree == NULL){
        return NULL_VALUE_INSERTED;
    }

    *tree = (BinSortTree*)calloc(1, sizeof(BinSortTree));

    (*tree)->root = (Node*)calloc(1, sizeof(Node));
    (*tree)->root->left = (left_tree) ? left_tree->root: NULL;
    (*tree)->root->right = (right_tree) ? right_tree->root: NULL;
    (*tree)->root->parent = NULL;

    (*tree)->root->data = 0;
    (*tree)->nodes_amount = 1;
    if (left_tree) (*tree)->nodes_amount += left_tree->nodes_amount;
    if (right_tree) (*tree)->nodes_amount += right_tree->nodes_amount;

    INIT_DEBUG_VARS(tree);

    BIN_SORT_TREE_VERIFY(tree);
    return NO_ERROR;
}

int createNode(Node** node, nodeData_t data){
    if (node == NULL){
        return NULL_VALUE_INSERTED;
    }

    *node = (Node*)calloc(1, sizeof(Node));

    (*node)->left = NULL;
    (*node)->right = NULL;
    (*node)->parent = NULL;

    (*node)->data = data;

    return NO_ERROR;
}

static int binSortTreeVerify(BinSortTree** tree){
    return NO_ERROR;
}

int printBinSortTree(BinSortTree* tree, TreePrintMode mode){
    BIN_SORT_TREE_VERIFY(&tree);

    printf("Binary sort tree: %s[%p]\n", tree->name, tree);
    printf("Born in %s:%s:%lu, amount of nodes: %lu\n", tree->filename, tree->funcname, tree->line, tree->nodes_amount);


    switch(mode){
        case (POSTFIX):{
            printf("Postfix: ");
            printNodePostfix(tree->root);
            break;
        }
        case(PREFIX):{
            printf("Prefix: ");
            printNodePrefix(tree->root);
            break;
        }
        case(INFIX):{
            printf("Infix: ");
            printNodeInfix(tree->root);
            break;
        }
        default:{
            return UNKNOWN_PRINT_MODE;
        }
    }

    printf("\n");

    return NO_ERROR;
}

static void printNodePostfix(Node* node){
    if (!node) return;

    printf("(");

    if (node->left) printNodePostfix(node->left);
    if (node->right) printNodePostfix(node->right);

    printf("%d", node->data);
    printf(")");
}

static void printNodePrefix(Node* node){
    if (!node) return;

    printf("(");
    printf("%d", node->data);

    if (node->left) printNodePrefix(node->left);
    if (node->right) printNodePrefix(node->right);

    printf(")");
}

static void printNodeInfix(Node* node){
    if (!node) return;

    printf("(");

    if (node->left) printNodeInfix(node->left);
    printf("%d", node->data);
    if (node->right) printNodeInfix(node->right);

    printf(")");
}