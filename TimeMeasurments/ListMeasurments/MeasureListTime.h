//
// Created by Luka Mitrovic on 19/04/2022.
//

#ifndef SDIZO_MEASURELISTTIME_H
#define SDIZO_MEASURELISTTIME_H
#include "../../DataTypes/LinkedList/LinkedList.h"
#include "../MeasureTime.h"

class MeasureListTime {
public:
    LinkedList *testList;
    MeasureTime time;

    void measurePushFront(int arraySize, int measurmentsAmount);
    void measurePushBack(int arraySize, int measurmentsAmount);
    void measurePushAtAnyPos(int arraySize, int measurmentsAmount);

    void measurePopFront(int arraySize, int measurmentsAmount);
    void measurePopBack(int arraySize, int measurmentsAmount);
    void measurePopAtAnyPos(int arraySize, int measurmentsAmount);

    void measureSearch(int arraySize, int measurmentsAmount);

    void executeAllTests();
};


#endif //SDIZO_MEASURELISTTIME_H
