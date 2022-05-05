//
// Created by Luka Mitrovic on 03/05/2022.
//

#include "Node.h"


Node::Node() {
    this->parent = nullptr;
    this->leftSon = nullptr;
    this->rightSon = nullptr;
    this->value = 0;
    this->color = 1;
}
