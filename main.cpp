#include <iostream>
#include "DataTypes/Array/Array.h"
#include "DataTypes/LinkedList/LinkedList.h"
#include "Menu/Menu.h"

int main() {
//    Menu* menu = new Menu();
//    menu->arrayCreationMenuMode();
//    menu->arrayOperationsMenuMode();

    LinkedList *list = new LinkedList("/Users/lukamitrovic/Desktop/testList.txt");
//    list->insertFront(1);
//    list->insertFront(2);
//    list->insertBack(3);
//    list->insertBack(4);
//    list->removeAt(0);
//    list->removeAt(1);
//    list->removeAt(2);
//    list->removeAt(2);
//    std::cout << list->find(1) << std::endl;

    list->print();

    return 0;
}
