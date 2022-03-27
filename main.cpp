#include <iostream>
#include "DataTypes/Array/Array.h"
#include "DataTypes/LinkedList/LinkedList.h"
#include "DataTypes/Heap/Heap.h"
#include "Menu/Menu.h"

int main() {
//    Menu* menu = new Menu();
//    menu->arrayCreationMenuMode();
//    menu->arrayOperationsMenuMode();
    Heap *heap = new Heap();
    heap->addElement(1);
    heap->addElement(2);
    heap->addElement(3);
    heap->addElement(4);
    heap->addElement(2);
    heap->addElement(2);

    heap->printAsArray();
    heap->print_tree();




    return 0;
}
