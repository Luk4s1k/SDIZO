//
// Created by Luka Mitrovic on 29/03/2022.
//

#include "HeapMenu.h"
#include <iostream>

void HeapMenu::heapCreationMenuMode() {
    int ListCreationOption;
    std::cout << " ------- Heap ---------- " << std::endl;
    std::cout << " 1 - Create custom heap"<< std::endl;
    std::cout << " 2 - Create heap from file"<< std::endl;
    std::cin >> ListCreationOption;
    if(ListCreationOption == 1){
        heapToOperateWith= new Heap();
        heapOperationsMenuMode();
    }else if (ListCreationOption == 2){
        std::string filename;
        std::cout << "FILE PATH:";
        std::cin >> filename;
        heapToOperateWith= new Heap(filename);
        heapToOperateWith->printAsArray();
        heapOperationsMenuMode();
    }else {
        std::cout << "INVALID OPTION !!!" << std::endl;
        heapCreationMenuMode();
    }
}

void HeapMenu::heapOperationsMenuMode() {
    int HeapOperationOption;
    int value = 0, index = 0;
    int positionFound = 0;
    std::cout << " ------- Heap ---------- " << std::endl;
    std::cout << " 1 - Add new key"<< std::endl;
    std::cout << " 2 - Show root value"<< std::endl;
    std::cout << " 3 - Remove root"<< std::endl;
    std::cout << " 4 - Remove element"<< std::endl;
    std::cout << " 5 - Search key"<< std::endl;
    std::cout << " 6 - Print in tree-type format"<< std::endl;
    std::cout << " 7 - EXIT "<< std::endl;
    std::cin >> HeapOperationOption;
    switch(HeapOperationOption){
        default:
            std::cout << "INVALID CHOICE" << std::endl;
            heapOperationsMenuMode();
        case 7:
            return;
        case 1:
            std::cout << "Value to add:";
            std::cin >> value;
            heapToOperateWith->addElement(value);
            heapToOperateWith->printAsArray();
            heapOperationsMenuMode();
            break;
        case 2:
            std::cout << "Root value is :" << heapToOperateWith->getRootValue() << std::endl;
            heapOperationsMenuMode();
            break;
        case 3:
            std::cout << "Root with value :" << heapToOperateWith->getRootValue();
            heapToOperateWith->extractRoot();
            std::cout << " Is extracted!" << std::endl;
            heapToOperateWith->printAsArray();
            heapOperationsMenuMode();
            break;
        case 4:
            std::cout << "Index of element to be deleted" << std::endl;
            std::cin >> index;
            heapToOperateWith->removeElement(index);
            heapToOperateWith->printAsArray();
            heapOperationsMenuMode();
        case 5:
            std::cout << "Value to search:";
            std::cin >> value;
            positionFound = heapToOperateWith->search(value);
            if (positionFound == -1) {std::cout << "NOT FOUND" << std::endl;}
            else {std::cout << "ELEMENT FOUND ON " << positionFound << " POSITION " << std::endl;}
            heapToOperateWith->printAsArray();
            heapOperationsMenuMode();
            break;
        case 6:
            heapToOperateWith->print_tree();
            heapOperationsMenuMode();
            break;

    }
}
