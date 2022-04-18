//
// Created by Luka Mitrovic on 12/02/2022.
//

#ifndef SDIZO_ARRAYMENU_H
#define SDIZO_ARRAYMENU_H
#include <iostream>
#include "../../DataTypes/Array/Array.h"

class ArrayMenu {
public:

    void arrayCreationMenuMode();
    void arrayOperationsMenuMode();

private:
    Array* arrayToOperateWith;
};


#endif //SDIZO_ARRAYMENU_H
