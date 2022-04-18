//
// Created by Luka Mitrovic on 29/03/2022.
//

#include "LinkedListMenu.h"
#include <iostream>

void LinkedListMenu::listCreationMenuMode() {
    int ListCreationOption;
    std::cout << " ------- List ---------- " << std::endl;
    std::cout << " 1 - Create custom list"<< std::endl;
    std::cout << " 2 - Create list from file"<< std::endl;
    std::cin >> ListCreationOption;
    if(ListCreationOption == 1){
        listToOperateWith= new LinkedList();
        listOperationsMenuMode();
    }else if (ListCreationOption == 2){
        std::string filename;
        std::cout << "FILE PATH:";
        std::cin >> filename;
        listToOperateWith= new LinkedList(filename);
        listOperationsMenuMode();
    }else {
        std::cout << "INVALID OPTION !!!" << std::endl;
        listCreationMenuMode();
    }
}

void LinkedListMenu::listOperationsMenuMode() {
    int ListOperationOption;
    int value, index;
    std::cout << " ------- List ---------- " << std::endl;
    std::cout << " 1 - Push element to the front"<< std::endl;
    std::cout << " 2 - Push element to the back"<< std::endl;
    std::cout << " 3 - Push element on the position"<< std::endl;
    std::cout << " 4 - Delete element from the front"<< std::endl;
    std::cout << " 5 - Delete element from the back"<< std::endl;
    std::cout << " 6 - Delete element from position"<< std::endl;
    std::cout << " 7 - Change element"<< std::endl;
    std::cout << " 8 - Search element "<< std::endl;
    std::cout << " 9 - EXIT "<< std::endl;
    std::cin >> ListOperationOption;
    switch(ListOperationOption){
        default:
            std::cout << "INVALID CHOICE" << std::endl;
            listOperationsMenuMode();
        case 9:
            return;
        case 1:
            std::cout << "Value to add:";
            std::cin >> value;
            listToOperateWith->insertFront(value);
            listToOperateWith->print();
            listOperationsMenuMode();
            break;
        case 2:
            std::cout << "Value to add:";
            std::cin >> value;
            listToOperateWith->insertBack(value);
            listToOperateWith->print();
            listOperationsMenuMode();
            break;
        case 3:
            std::cout << "Value to add:";
            std::cin >> value;
            std::cout << "Position to put value in:";
            std::cin >> index;
            listToOperateWith->insertAt(index, value);
            listToOperateWith->print();
            listOperationsMenuMode();
            break;
        case 4:
            listToOperateWith->removeFront();
            listToOperateWith->print();
            listOperationsMenuMode();
            break;
        case 5:
            listToOperateWith->removeBack();
            listToOperateWith->print();
            listOperationsMenuMode();
            break;
        case 6:
            std::cout << "Position to delete value at:";
            std::cin >> index;
            listToOperateWith->removeAt(index);
            listToOperateWith->print();
            listOperationsMenuMode();
            break;
        case 7:
            std::cout << "Element to change is on position:";
            std::cin >> index;
            std::cout << "New value:";
            std::cin >> value;
            listToOperateWith->getElem(index)->value = value;
            listToOperateWith->print();
            listOperationsMenuMode();
            break;
        case 8:
            std::cout << "Value to search:";
            std::cin >> value;
            int positionOfFoundElement = listToOperateWith->find(value);
            if (positionOfFoundElement == -1) {std::cout << "NOT FOUND" << std::endl;}
            else {std::cout << "ELEMENT IS ON " << positionOfFoundElement << " POSITION" << std::endl;}
            listToOperateWith->print();
            listOperationsMenuMode();
            break;
    }
}
