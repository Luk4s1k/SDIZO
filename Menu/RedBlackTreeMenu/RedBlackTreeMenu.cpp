//
// Created by Luka Mitrovic on 03/05/2022.
//

#include "RedBlackTreeMenu.h"

void RedBlackTreeMenu::treeCreationMenuMode() {
    int TreeCreationOption;
    std::cout << " ------- Tree ---------- " << std::endl;
    std::cout << " 1 - Create custom tree"<< std::endl;
    std::cout << " 2 - Create tree from file"<< std::endl;
    std::cin >> TreeCreationOption;
    if(TreeCreationOption == 1){
        treeToOperateWith = new RBTree();
        treeOperationsMenuMode();
    }else if (TreeCreationOption == 2){
        std::string filename;
        std::cout << "FILE PATH:";
        std::cin >> filename;
        treeToOperateWith = new RBTree(filename);
        treeToOperateWith->print();
        treeOperationsMenuMode();
    }else {
        std::cout << "INVALID OPTION !!!" << std::endl;
        treeCreationMenuMode();
    }
}

void RedBlackTreeMenu::treeOperationsMenuMode() {
    int treeOperationOption;
    int value, index;
    std::cout << " ------- Tree ---------- " << std::endl;
    std::cout << " 1 - Insert Element"<< std::endl;
    std::cout << " 2 - Remove Element"<< std::endl;
    std::cout << " 3 - Search Element"<< std::endl;
    std::cout << " 4 - EXIT "<< std::endl;
    std::cin >> treeOperationOption;
    switch(treeOperationOption){
        default:
            std::cout << "INVALID CHOICE" << std::endl;
            treeOperationsMenuMode();
        case 4:
            return;
        case 1:
            std::cout << "Value to add:";
            std::cin >> value;
            treeToOperateWith->insertElement(value);
            treeToOperateWith->print();
            treeOperationsMenuMode();
            break;
        case 2:
            std::cout << "Value to remove:";
            std::cin >> value;
            treeToOperateWith->removeElement(treeToOperateWith->getRoot(),value);
            treeToOperateWith->print();
            treeOperationsMenuMode();
            break;
        case 3:
            std::cout << "Value to search:";
            std::cin >> value;
            auto positionOfFoundElement = treeToOperateWith->search(treeToOperateWith->getRoot(),value);
            if (positionOfFoundElement == treeToOperateWith->getNullNode()) {std::cout << "NOT FOUND" << std::endl;}
            else {std::cout << "ELEMENT APPEARS ON TREE" << std::endl;}
            treeToOperateWith->print();
            treeOperationsMenuMode();
            break;
    }
}
