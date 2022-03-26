//
// Created by Luka Mitrovic on 12/02/2022.
//

#ifndef SDIZO_MENU_H
#define SDIZO_MENU_H
#include <iostream>
#include "DataTypes/Array.h"

class Menu {
public:
    void DataChooseMode();

    void arrayCreationMenuMode();
    void arrayOperationsMenuMode();

private:
    Array* arrayToOperateWith;
};


#endif //SDIZO_MENU_H
