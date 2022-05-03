//
// Created by Luka Mitrovic on 03/05/2022.
//

#ifndef SDIZO_REDBLACKTREEMENU_H
#define SDIZO_REDBLACKTREEMENU_H
#include "../../DataTypes/RBTree/RBTree.h"

class RedBlackTreeMenu {
public:

    void treeCreationMenuMode();
    void treeOperationsMenuMode();

private:
    RBTree* treeToOperateWith;
};


#endif //SDIZO_REDBLACKTREEMENU_H
