//
// Created by Luka Mitrovic on 18/04/2022.
//

#include "MeasureTime.h"

void MeasureTime::measureStart() {
    this->startTime = high_resolution_clock::now();
}

void MeasureTime::measureEnd() {
    this->endTime = high_resolution_clock::now();
}

long MeasureTime::getTime() {
    return duration_cast<nanoseconds>(endTime - startTime).count();;
}
