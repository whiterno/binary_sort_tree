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

//! @brief Typedef is made to change node's data type
typedef int nodeData_t;

//! @brief Node structure, that contains pointers on left, right and parent nodes and data
struct Node{
    nodeData_t data;        ///< node's data
    Node* parent;           ///< pointer on the parent node in tree
    Node* left;             ///< pointer on the left node in tree (its data is less or equal than this node's data)
    Node* right;            ///< pointer on the right node in tree (its data is bigger than this node's data)
};

//! @brief Main structure with debug info, pointer on tree's root and amount of nodes in tree
struct BinSortTree{
    const char* name;       ///< tree's name
    const char* filename;   ///< filename where tree was initialized
    const char* funcname;   ///< funcname where tree was initialized
    size_t line;            ///< serial number of line where tree was initialized

    Node* root;             ///< pointer on tree's root
    int nodes_amount;       ///< amount of nodes in tree
};

//! @brief Errors enumerator
enum Errors{
    NO_ERROR,               ///< no errors occured
    NULL_VALUE_INSERTED,    ///< NULL value was given as an argument for functions
    UNKNOWN_PRINT_MODE,     ///< print mode was neither PREFIX, INFIX nor POSTFIX
    CYCLE_IN_TREE,          ///< tree contains cycles in it
    FILE_NOT_OPEN,          ///< dump file couldn't open
};

//! @brief Tree console print mode enumeartor
enum TreePrintMode{
    POSTFIX,                ///< ( node (node.left) (node.right) )
    PREFIX,                 ///< ( (node.left) (node.right) node )
    INFIX,                  ///< ( (node.left) node (node.right) )
};

int binSortTreeCtor(BinSortTree** tree, BinSortTree* left_tree, BinSortTree* right_tree INIT_ARGS);
int createNode(Node** node, nodeData_t data);
int printBinSortTree(BinSortTree* tree, TreePrintMode mode);
int binSortTreePush(BinSortTree* tree, nodeData_t data);
int binSortTreeDtor(BinSortTree** tree);

#endif
