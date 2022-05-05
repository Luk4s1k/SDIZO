//
// Created by Luka Mitrovic on 05/05/2022.
//

#ifndef SDIZO_RBTREEMEASURMENTS_H
#define SDIZO_RBTREEMEASURMENTS_H
#include "../../DataTypes/RBTree/RBTree.h"
#include "../MeasureTime.h"
#include <fstream>
#define REMOVE_FILE "/Users/lukamitrovic/Desktop/TreeResults/tree_add.txt"
#define ADD_FILE "/Users/lukamitrovic/Desktop/TreeResults/tree_remove.txt"
#define SEARCH_FILE "/Users/lukamitrovic/Desktop/TreeResults/tree_search.txt"


class RBTreeMeasurments {
public:
    RBTree *testTree;
    MeasureTime time;

    void measureAddElement(int treeSize, int measurmentsAmount);
    void measureRemoveElement(int treeSize, int measurmentsAmount);
    void measureSearch(int treeSize, int measurmentsAmount);

    void executeAllTests();
};


#endif //SDIZO_RBTREEMEASURMENTS_H
