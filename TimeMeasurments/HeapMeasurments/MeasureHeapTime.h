//
// Created by Luka Mitrovic on 19/04/2022.
//

#ifndef SDIZO_MEASUREHEAPTIME_H
#define SDIZO_MEASUREHEAPTIME_H
#include "../../DataTypes/Heap/Heap.h"
#include "../MeasureTime.h"

class MeasureHeapTime {
public:
    Heap *testHeap;
    MeasureTime time;

    void measureAddElement(int arraySize, int measurmentsAmount);
    void measureRemoveElement(int arraySize, int measurmentsAmount);
    void measureSearch(int arraySize, int measurmentsAmount);

    void executeAllTests();
};


#endif //SDIZO_MEASUREHEAPTIME_H
