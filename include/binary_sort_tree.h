#ifndef BINARY_SORT_TREE_H
#define BINARY_SORT_TREE_H

#include <stdio.h>

#define BIN_SORT_TREE_VERIFY(binSortTree){                  \
    int error = 0;                                          \
    if ((error = binSortTreeVerify(binSortTree))){          \
        return error;                                       \
    }                                                       \
}
#define INIT(binSortTree) , #binSortTree, __FILE__, __func__, __LINE__
#define INIT_ARGS , const char* name, const char* filename, const char* funcname, size_t line
#define INIT_DEBUG_VARS(binSortTree) (*binSortTree)->name = name; (*binSortTree)->filename = filename; (*binSortTree)->funcname = funcname; (*binSortTree)->line = line;
#define DUMP(binSortTree) binSortTree, __FILE__, __func__, __LINE__

//! @brief Dump .dot filename for png creating
const char DUMP_DOT_FILENAME[] = "log/dump.dot";

//! @brief Dump .html filename for html dump with log and images
const char DUMP_HTML_FILENAME[] = "log/dump.html";

typedef int nodeData_t;

struct Node{
    nodeData_t data;
    Node* parent;
    Node* left;
    Node* right;
};

struct BinSortTree{
    const char* name;       ///< tree's name
    const char* filename;   ///< filename where tree was initialized
    const char* funcname;   ///< funcname where tree was initialized
    size_t line;            ///< serial number of line where tree was initialized

    Node* root;
    int nodes_amount;
};

enum Errors{
    NO_ERROR,
    NULL_VALUE_INSERTED,
    UNKNOWN_PRINT_MODE,
    CYCLE_IN_TREE,
    FILE_NOT_OPEN,
};

enum TreePrintMode{
    POSTFIX,
    PREFIX,
    INFIX,
};

int binSortTreeCtor(BinSortTree** tree, BinSortTree* left_tree, BinSortTree* right_tree INIT_ARGS);
int createNode(Node** node, nodeData_t data);
int printBinSortTree(BinSortTree* tree, TreePrintMode mode);
int binSortTreePush(BinSortTree* tree, nodeData_t data);

#endif
