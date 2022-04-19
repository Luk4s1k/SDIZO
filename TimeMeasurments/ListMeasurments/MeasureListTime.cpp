//
// Created by Luka Mitrovic on 19/04/2022.
//

#include "MeasureListTime.h"
#include <fstream>
#define PUSH_FRONT_FILE "/Users/lukamitrovic/Desktop/ListResults/list_push_front.txt"
#define PUSH_BACK_FILE "/Users/lukamitrovic/Desktop/ListResults/list_push_back.txt"
#define PUSH_FILE "/Users/lukamitrovic/Desktop/ListResults/list_push.txt"
#define POP_FRONT_FILE "/Users/lukamitrovic/Desktop/ListResults/list_pop_front.txt"
#define POP_BACK_FILE "/Users/lukamitrovic/Desktop/ListResults/list_pop_back.txt"
#define POP_FILE "/Users/lukamitrovic/Desktop/ListResults/list_pop.txt"
#define SEARCH_FILE "/Users/lukamitrovic/Desktop/ListResults/list_search.txt"

void MeasureListTime::measurePushFront(int arraySize, int measurmentsAmount) {
    testList = new LinkedList(arraySize);
    std::ofstream myfile;
    long averagetime = 0;
    myfile.open (PUSH_FRONT_FILE,std::fstream::app);
    for (int i = 0; i < measurmentsAmount; i++){
        int value = rand()%1000;
        time.measureStart();
        testList->insertFront(value);
        time.measureEnd();
        testList->removeFront();
        averagetime += time.getTime();
    }
    myfile << "PushFront for " << arraySize << " elements and " << measurmentsAmount << " measurments : " << averagetime/measurmentsAmount << std::endl;
    myfile.close();
    delete testList;
}

void MeasureListTime::measurePushBack(int arraySize, int measurmentsAmount) {
    testList = new LinkedList(arraySize);
    std::ofstream myfile;
    long averagetime = 0;
    myfile.open (PUSH_BACK_FILE,std::fstream::app);
    for (int i = 0; i < measurmentsAmount; i++){
        int value = rand()%1000;
        time.measureStart();
        testList->insertBack(value);
        time.measureEnd();
        testList->removeBack();
        averagetime += time.getTime();
    }
    myfile << "PushBack for " << arraySize << " elements and " << measurmentsAmount << " measurments : " << averagetime/measurmentsAmount << std::endl;
    myfile.close();
    delete testList;
}

void MeasureListTime::measurePushAtAnyPos(int arraySize, int measurmentsAmount) {
    testList = new LinkedList(arraySize);
    std::ofstream myfile;
    long averagetime = 0;
    myfile.open (PUSH_FILE,std::fstream::app);
    for (int i = 0; i < measurmentsAmount; i++){
        int value = rand()%1000;
        time.measureStart();
        testList->insertAt(testList->getLength()/2,value);
        time.measureEnd();
        testList->removeAt(testList->getLength()/2);
        averagetime += time.getTime();
    }
    myfile << "PushAnyPos for " << arraySize << " elements and " << measurmentsAmount << " measurments : " << averagetime/measurmentsAmount << std::endl;
    myfile.close();
    delete testList;
}

void MeasureListTime::measurePopFront(int arraySize, int measurmentsAmount) {
    testList = new LinkedList();
    std::ofstream myfile;
    long averagetime = 0;
    myfile.open (POP_FRONT_FILE,std::fstream::app);
    for (int i = 0; i < arraySize; i++){
        int value = rand()%1000;
        testList->insertBack(value);
    }
    for (int i = 0; i < measurmentsAmount; i++){
        int value = rand()%1000;
        time.measureStart();
        testList->removeFront();
        time.measureEnd();
        testList->insertFront(value);
        averagetime += time.getTime();
    }
    myfile << "PopFront for " << arraySize << " elements and " << measurmentsAmount << " measurments : " << averagetime/measurmentsAmount << std::endl;
    myfile.close();
    delete testList;
}

void MeasureListTime::measurePopBack(int arraySize, int measurmentsAmount) {
    testList = new LinkedList();
    std::ofstream myfile;
    long averagetime = 0;
    myfile.open (POP_BACK_FILE,std::fstream::app);
    for (int i = 0; i < arraySize; i++){
        int value = rand()%1000;
        testList->insertBack(value);
    }
    for (int i = 0; i < measurmentsAmount; i++){
        time.measureStart();
        testList->removeBack();
        time.measureEnd();
        int value = rand()%1000;
        testList->insertBack(value);
        averagetime += time.getTime();
    }
    myfile << "PopBack for " << arraySize << " elements and " << measurmentsAmount << " measurments : " << averagetime/measurmentsAmount << std::endl;
    myfile.close();
    delete testList;
}

void MeasureListTime::measurePopAtAnyPos(int arraySize, int measurmentsAmount) {
    testList = new LinkedList();
    std::ofstream myfile;
    long averagetime = 0;
    myfile.open (POP_FILE,std::fstream::app);
    for (int i = 0; i < arraySize; i++){
        int value = rand()%1000;
        testList->insertBack(value);
    }
    for (int i = 0; i < measurmentsAmount; i++){
        int value = rand()%1000;
        time.measureStart();
        testList->removeAt(testList->getLength()/2);
        time.measureEnd();
        testList->insertAt(testList->getLength()/2,value);
        averagetime += time.getTime();
    }
    myfile << "PopAnyPos for " << arraySize << " elements and " << measurmentsAmount << " measurments : " << averagetime/measurmentsAmount << std::endl;
    myfile.close();
    delete testList;
}

void MeasureListTime::measureSearch(int arraySize, int measurmentsAmount) {
    testList = new LinkedList();
    std::ofstream myfile;
    long averagetime = 0;
    int searchVal = 0;
    myfile.open (SEARCH_FILE,std::fstream::app);
    for (int i = 0; i < arraySize; i++){
        int value = rand()%1000;
        testList->insertBack(value);
        if (i == arraySize - 2) {
            searchVal = value;
        }
    }
    for (int i = 0; i < measurmentsAmount; i++){
        time.measureStart();
        testList->find(searchVal);
        time.measureEnd();
        averagetime += time.getTime();
    }
    myfile << "Search for " << arraySize << " elements and " << measurmentsAmount << " measurments : " << averagetime/measurmentsAmount << std::endl;
    myfile.close();
    delete testList;
}

void MeasureListTime::executeAllTests() {
    for (int i = 10; i <= 10000; i *= 10){
        measurePushFront(i,50);
        measurePushBack(i,50);
        measurePushAtAnyPos(i,50);
        measurePopFront(i,50);
        measurePopBack(i,50);
        measurePopAtAnyPos(i,50);
        measureSearch(i,50);
    }
    for (int i = 20000; i <= 60000; i *= 2){
        measurePushFront(i,50);
        measurePushBack(i,50);
        measurePushAtAnyPos(i,50);
        measurePopFront(i,50);
        measurePopBack(i,50);
        measurePopAtAnyPos(i,50);
        measureSearch(i,50);
    }
    measurePushFront(100000,50);
    measurePushBack(100000,50);
    measurePushAtAnyPos(100000,50);
    measurePopFront(100000,50);
    measurePopBack(100000,50);
    measurePopAtAnyPos(100000,50);
    measureSearch(100000,50);
}
