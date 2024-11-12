#ifndef BIN_SORT_TREE_DUMP_H
#define BIN_SORT_TREE_DUMP_H

const int MAX_ATTRIBUTE_SIZE = 32;

//! @brief Max amount of symbols in cmd string for system() call
const int MAX_CMD_SIZE = 64;

struct TreeDumpAttributes{
    char node_color         [MAX_ATTRIBUTE_SIZE];
    char node_shape         [MAX_ATTRIBUTE_SIZE];
    char node_fillcolor     [MAX_ATTRIBUTE_SIZE];

    char edge_arrowhead     [MAX_ATTRIBUTE_SIZE];
    char edge_color         [MAX_ATTRIBUTE_SIZE];

};

int binSortTreeDump(BinSortTree* tree, const char filename[], const char funcname[], const size_t line, int error);

#endif
