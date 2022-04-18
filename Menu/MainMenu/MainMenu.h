//
// Created by Luka Mitrovic on 29/03/2022.
//

#ifndef SDIZO_MAINMENU_H
#define SDIZO_MAINMENU_H
#include "../ArrayMenu/ArrayMenu.h"
#include "../ListMenu/LinkedListMenu.h"
#include "../HeapMenu/HeapMenu.h"

class MainMenu {
public:
    void mainMenuMode();
private:
    ArrayMenu *arrayMenu;
    LinkedListMenu *listMenu;
    HeapMenu *heapMenu;

};


#endif //SDIZO_MAINMENU_H
