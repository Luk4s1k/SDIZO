//
// Created by Luka Mitrovic on 12/02/2022.
//

#include "ArrayMenu.h"

void ArrayMenu::arrayCreationMenuMode() {
    int ArrayCreationOption;
    std::cout << " ------- ARRAY ---------- " << std::endl;
    std::cout << " 1 - Create custom array"<< std::endl;
    std::cout << " 2 - Create array from file"<< std::endl;
    std::cin >> ArrayCreationOption;
    if(ArrayCreationOption == 1){
        arrayToOperateWith= new Array();
        arrayOperationsMenuMode();
    }else if (ArrayCreationOption == 2){
        std::string filename;
        std::cout << "FILE PATH:";
        std::cin >> filename;
        arrayToOperateWith= new Array(filename);
        arrayOperationsMenuMode();
    }else {
        std::cout << "INVALID OPTION !!!" << std::endl;
        arrayCreationMenuMode();
    }
}

void ArrayMenu::arrayOperationsMenuMode() {
    int ArrayOperationOption;
    int value, index;
    std::cout << " ------- ARRAY ---------- " << std::endl;
    std::cout << " 1 - Push element to the front"<< std::endl;
    std::cout << " 2 - Push element to the back"<< std::endl;
    std::cout << " 3 - Push element on the position"<< std::endl;
    std::cout << " 4 - Delete element from the front"<< std::endl;
    std::cout << " 5 - Delete element from the back"<< std::endl;
    std::cout << " 6 - Delete element from position"<< std::endl;
    std::cout << " 7 - Change element"<< std::endl;
    std::cout << " 8 - Search element "<< std::endl;
    std::cout << " 9 - EXIT "<< std::endl;
    std::cin >> ArrayOperationOption;
    switch(ArrayOperationOption){
        default:
            std::cout << "INVALID CHOICE" << std::endl;
            arrayOperationsMenuMode();
        case 9:
            return;
        case 1:
            std::cout << "Value to add:";
            std::cin >> value;
            arrayToOperateWith->push_front(value);
            arrayToOperateWith->print();
            arrayOperationsMenuMode();
            break;
        case 2:
            std::cout << "Value to add:";
            std::cin >> value;
            arrayToOperateWith->push_back(value);
            arrayToOperateWith->print();
            arrayOperationsMenuMode();
            break;
        case 3:
            std::cout << "Value to add:";
            std::cin >> value;
            std::cout << "Position to put value in:";
            std::cin >> index;
            arrayToOperateWith->push(index, value);
            arrayToOperateWith->print();
            arrayOperationsMenuMode();
            break;
        case 4:
            arrayToOperateWith->pop_front();
            arrayToOperateWith->print();
            arrayOperationsMenuMode();
            break;
        case 5:
            arrayToOperateWith->pop_back();
            arrayToOperateWith->print();
            arrayOperationsMenuMode();
            break;
        case 6:
            std::cout << "Position to delete value at:";
            std::cin >> index;
            arrayToOperateWith->pop(index);
            arrayToOperateWith->print();
            arrayOperationsMenuMode();
            break;
        case 7:
            std::cout << "Element to change is on position:";
            std::cin >> index;
            std::cout << "New value:";
            std::cin >> value;
            arrayToOperateWith->modify(index,value);
            arrayToOperateWith->print();
            arrayOperationsMenuMode();
            break;
        case 8:
            std::cout << "Value to search:";
            std::cin >> value;
            int positionOfFoundElement = arrayToOperateWith->search(value);
            if (positionOfFoundElement == -1) {std::cout << "NOT FOUND" << std::endl;}
            else {std::cout << "ELEMENT IS ON " << positionOfFoundElement << " POSITION" << std::endl;}
            arrayToOperateWith->print();
            arrayOperationsMenuMode();
            break;
    }
}
