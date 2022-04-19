//
// Created by Luka Mitrovic on 18/04/2022.
//

#ifndef SDIZO_MEASURETIME_H
#define SDIZO_MEASURETIME_H
#include <iostream>
#include <chrono>

using namespace std::chrono;
class MeasureTime {
public:
    high_resolution_clock::time_point startTime;
    high_resolution_clock::time_point endTime;

    void measureStart();

    void measureEnd();

    long getTime();
};


#endif //SDIZO_MEASURETIME_H
