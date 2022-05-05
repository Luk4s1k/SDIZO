//
// Created by Luka Mitrovic on 05/05/2022.
//

#include "RBTreeMeasurments.h"

void RBTreeMeasurments::measureAddElement(int treeSize, int measurmentsAmount) {
    testTree = new RBTree();
    std::ofstream myfile;
    long averagetime = 0;
    for(int i = 0; i < treeSize; i++){
        int value = rand()%1000;
        testTree->insertElement(value);
    }
    myfile.open (ADD_FILE,std::fstream::app);
    for (int i = 0; i < measurmentsAmount; i++){
        int value = rand()%1000;
        time.measureStart();
        testTree->insertElement(value);
        time.measureEnd();
        testTree->removeElement(testTree->getRoot(),value);
        averagetime += time.getTime();
    }
    myfile << "Add ELEM  for " << treeSize << " elements and " << measurmentsAmount << " measurments : " << averagetime/measurmentsAmount << std::endl;
    myfile.close();
    delete testTree;
}

void RBTreeMeasurments::measureRemoveElement(int treeSize, int measurmentsAmount) {
    testTree = new RBTree();
    std::ofstream myfile;
    long averagetime = 0;
    for(int i = 0; i < treeSize; i++){
        int value = rand()%1000;
        testTree->insertElement(value);
    }
    myfile.open (REMOVE_FILE,std::fstream::app);
    for (int i = 0; i < measurmentsAmount; i++){
        int value = rand()%1000;
        time.measureStart();
        testTree->removeElement(testTree->getRoot(),value);
        time.measureEnd();
        testTree->insertElement(value);
        averagetime += time.getTime();
    }
    myfile << "Remove ELEM  for " << treeSize << " elements and " << measurmentsAmount << " measurments : " << averagetime/measurmentsAmount << std::endl;
    myfile.close();
    delete testTree;
}

void RBTreeMeasurments::measureSearch(int treeSize, int measurmentsAmount) {
    testTree = new RBTree();
    std::ofstream myfile;
    long averagetime = 0;
    int searchVal = 0;
    for(int i = 0; i < treeSize; i++){
        int value = rand()%1000;
        testTree->insertElement(value);
        if (i == treeSize - 2) {
            searchVal = value;
        }
    }
    myfile.open (SEARCH_FILE,std::fstream::app);
    for (int i = 0; i < measurmentsAmount; i++){
        int value = rand()%1000;
        time.measureStart();
        testTree->search(testTree->getRoot(),value);
        time.measureEnd();
        averagetime += time.getTime();
    }
    myfile << "Search ELEM  for " << treeSize << " elements and " << measurmentsAmount << " measurments : " << averagetime/measurmentsAmount << std::endl;
    myfile.close();
    delete testTree;
}

void RBTreeMeasurments::executeAllTests() {
    for (int i = 10; i <= 10000; i *= 10){
        measureAddElement(i,100);
        measureRemoveElement(i,100);
        measureSearch(i,100);
    }
    for (int i = 20000; i <= 60000; i *= 2){
        measureAddElement(i,100);
        measureRemoveElement(i,100);
        measureSearch(i,100);
    }
    measureAddElement(100000,100);
    measureRemoveElement(100000,100);
    measureSearch(100000,100);
}
