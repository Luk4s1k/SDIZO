#include <iostream>
#include "Menu/MainMenu/MainMenu.h"
#include "TimeMeasurments/ArrayMeasurments/MeasureArrayTime.h"

int main() {
//    MainMenu *menu = new MainMenu();
//    menu->mainMenuMode();
    MeasureArrayTime *ma = new MeasureArrayTime();
    ma->executeAllTests();
    //delete ma;

    return 0;
}
