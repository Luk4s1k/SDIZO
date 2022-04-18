//
// Created by Luka Mitrovic on 29/03/2022.
//

#ifndef SDIZO_LINKEDLISTMENU_H
#define SDIZO_LINKEDLISTMENU_H
#include "../../DataTypes/LinkedList/LinkedList.h"

class LinkedListMenu {
public:

    void listCreationMenuMode();
    void listOperationsMenuMode();

private:
    LinkedList* listToOperateWith;
};


#endif //SDIZO_LINKEDLISTMENU_H
