#include <iostream>
#include "Menu/MainMenu/MainMenu.h"
#include "TimeMeasurments/ListMeasurments/MeasureListTime.h"
#include "TimeMeasurments/ArrayMeasurments/MeasureArrayTime.h"
#include "TimeMeasurments/HeapMeasurments/MeasureHeapTime.h"

int main() {
//        MainMenu *menu = new MainMenu();
//        menu->mainMenuMode();
    //    MeasureListTime *ma = new MeasureListTime();
    //    ma->executeAllTests();
//    MeasureListTime *ma = new MeasureListTime();
//    ma->executeAllTests();
    MeasureHeapTime *ma = new MeasureHeapTime();
    ma->executeAllTests();


    return 0;
}
