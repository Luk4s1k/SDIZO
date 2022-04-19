//
// Created by Luka Mitrovic on 19/04/2022.
//

#include "MeasureHeapTime.h"
#include <fstream>
#define REMOVE_FILE "/Users/lukamitrovic/Desktop/HeapResults/heap_add.txt"
#define ADD_FILE "/Users/lukamitrovic/Desktop/HeapResults/heap_remove.txt"
#define SEARCH_FILE "/Users/lukamitrovic/Desktop/HeapResults/heap_search.txt"

void MeasureHeapTime::measureAddElement(int arraySize, int measurmentsAmount) {
    testHeap = new Heap(arraySize);
    std::ofstream myfile;
    long averagetime = 0;
    myfile.open (ADD_FILE,std::fstream::app);
    for (int i = 0; i < measurmentsAmount; i++){
        int value = rand()%1000;
        time.measureStart();
        testHeap->addElement(value);
        time.measureEnd();
        testHeap->extractRoot();
        averagetime += time.getTime();
    }
    myfile << "Add ELEM  for " << arraySize << " elements and " << measurmentsAmount << " measurments : " << averagetime/measurmentsAmount << std::endl;
    myfile.close();
    delete testHeap;
}

void MeasureHeapTime::measureRemoveElement(int arraySize, int measurmentsAmount) {
    testHeap = new Heap();
    std::ofstream myfile;
    long averagetime = 0;
    for (int i = 0; i < arraySize; i++){
        int value = rand()%1000;
        testHeap->addElement(value);
    }
    myfile.open (REMOVE_FILE,std::fstream::app);
    for (int i = 0; i < measurmentsAmount; i++){
        int value = rand()%1000;
        time.measureStart();
        testHeap->extractRoot();
        time.measureEnd();
        testHeap->addElement(value);
        averagetime += time.getTime();
    }
    myfile << "Remove  for " << arraySize << " elements and " << measurmentsAmount << " measurments : " << averagetime/measurmentsAmount << std::endl;
    myfile.close();
    delete testHeap;
}

void MeasureHeapTime::measureSearch(int arraySize, int measurmentsAmount) {
    testHeap = new Heap();
    std::ofstream myfile;
    long averagetime = 0;
    int searchVal = 0;
    myfile.open (SEARCH_FILE,std::fstream::app);
    for (int i = 0; i < arraySize; i++){
        int value = rand()%1000;
        testHeap->addElement(value);
        if (i == arraySize - 2) {
            searchVal = value;
        }
    }
    for (int i = 0; i < measurmentsAmount; i++){
        time.measureStart();
        testHeap->search(0,searchVal);
        time.measureEnd();
        averagetime += time.getTime();
    }
    myfile << "Search for " << arraySize << " elements and " << measurmentsAmount << " measurments : " << averagetime/measurmentsAmount << std::endl;
    myfile.close();
    delete testHeap;
}

void MeasureHeapTime::executeAllTests() {
    for (int i = 10; i < 1000000; i *= 10){
        measureAddElement(i,50);
        measureRemoveElement(i,50);
        measureSearch(i,50);
    }
}
