//
// Created by Luka Mitrovic on 14/03/2022.
//

#include "LinkedList.h"

LinkedList::LinkedList() {
    head = new Node();
    tail = new Node();
    length = 0;

}

LinkedList::LinkedList(std::string filename) {

}

void LinkedList::insertFront(int value) {
    Node* newNode = new Node(value);
    if (length == 0){
        head = newNode;
        tail = newNode;
    }else

}
