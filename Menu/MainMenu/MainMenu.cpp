//
// Created by Luka Mitrovic on 29/03/2022.
//

#include "MainMenu.h"

void MainMenu::mainMenuMode() {
    int structureChoice;
    std::cout << "---------- Structures ---------" << std::endl;
    std::cout << "----- 1 - Array           (Tablica) " << std::endl;
    std::cout << "----- 2 - LinkedList      (Dwukierunkowa lista) " << std::endl;
    std::cout << "----- 3 - Heap            (Kopiec) " << std::endl;
    std::cout << "----- 4 - Red-Black Tree  (Drzewo czerwono-czarne) " << std::endl;
    std::cout << "----- 5 - Exit " << std::endl;
    std::cin >> structureChoice;

    switch (structureChoice){
        case 1: arrayMenu = new ArrayMenu();
            arrayMenu->arrayCreationMenuMode();
            mainMenuMode();
            break;
        case 2:
            listMenu = new LinkedListMenu();
            listMenu->listCreationMenuMode();
            mainMenuMode();
            break;
        case 3:
            heapMenu = new HeapMenu();
            heapMenu->heapCreationMenuMode();
            mainMenuMode();
            break;
        case 4:
            break;
//            rbtreeMenu = new RedBlackTreeMenu();
//            rbtreeMenu->rbTreeCreationMenuMode();
//            mainMenuMode();
//            break;
        case 5:
            return;
    }
}
