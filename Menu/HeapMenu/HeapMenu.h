//
// Created by Luka Mitrovic on 29/03/2022.
//

#ifndef SDIZO_HEAPMENU_H
#define SDIZO_HEAPMENU_H
#include "../../DataTypes/Heap/Heap.h"

class HeapMenu {
public:
    void heapCreationMenuMode();
    void heapOperationsMenuMode();
private:
    Heap *heapToOperateWith;
};


#endif //SDIZO_HEAPMENU_H
