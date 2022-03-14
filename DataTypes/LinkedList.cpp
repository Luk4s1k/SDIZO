//
// Created by Luka Mitrovic on 14/03/2022.
//

#include "LinkedList.h"

LinkedList::LinkedList() {
    head = new ListNode(0, nullptr, nullptr);
    tail ;
    length = 0;

}

LinkedList::LinkedList(std::string filename) {

}

void LinkedList::insertFront(int value) {
    ListNode* newNode = new ListNode(value, nullptr, nullptr);
    if (length == 0){
        head = newNode;
        tail = newNode;
    }else

}
