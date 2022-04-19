//
// Created by Luka Mitrovic on 18/04/2022.
//

#ifndef SDIZO_MEASUREARRAYTIME_H
#define SDIZO_MEASUREARRAYTIME_H
#include "../../DataTypes/Array/Array.h"
#include "../MeasureTime.h"

class MeasureArrayTime {
public:
    Array *testArray;
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


#endif //SDIZO_MEASUREARRAYTIME_H
