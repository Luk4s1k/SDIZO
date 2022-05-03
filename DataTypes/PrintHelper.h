//
// Created by Luka Mitrovic on 03/05/2022.
//

#ifndef SDIZO_PRINTHELPER_H
#define SDIZO_PRINTHELPER_H
#include "RBTree/RBTree.h"
#include "Array/Array.h"

class PrintHelper {
public:
    void printLevelOrder(Node* root);
    void test();
    void printCurrentLevel(Node *root, int level);
    int height(Node *node);
    std::string do_padding(unsigned index, unsigned mlength);
    void printer(unsigned index, unsigned mlength);
    void print_tree();
    PrintHelper(RBTree *tree);

    RBTree *tree;
    Array *arr;
};


#endif //SDIZO_PRINTHELPER_H
