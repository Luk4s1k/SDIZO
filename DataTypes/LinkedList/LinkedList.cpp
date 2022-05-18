//
// Created by Luka Mitrovic on 14/03/2022.
//

#include <iostream>
#include <fstream>
#include "LinkedList.h"

LinkedList::LinkedList() {
    head = tail = nullptr;
    length = 0;
}

LinkedList::LinkedList(int size) {
    head = tail = nullptr;
    length = 0;
    for (int i = 0;i < size;i++){
        insertBack(0);
    }
}

LinkedList::LinkedList(std::string filename) {
    std::ifstream file;
    int arraySizeFromFile;
    int readVal, i;
    file.open(filename);
    if(file.is_open()){
        file >> arraySizeFromFile;
        while(file.good()){
            file >> readVal;
            insertBack(readVal);
        }
    }
    if (length != arraySizeFromFile) std::cout << "INVALID SIZE OF ARRAY PROVIDED IN FILE" << std::endl;
    file.close();
}

void LinkedList::insertFront(int value) {
    ListNode *newNode = new ListNode(value, head, nullptr);
    if (head != nullptr) {
        head->prev = newNode;
    }
    else{
        tail = newNode;
    }
    head = newNode;
    length++;

}

void LinkedList::insertBack(int value) {
    ListNode *newNode = new ListNode(value,nullptr, tail);
    if (tail != nullptr) {
        tail->next = newNode;
    }
    else{
        head = newNode;
    }
    tail = newNode;
    length++;

}

void LinkedList::insertAt(unsigned int position, int value) {
    if (position > length){
        std::cout<<"Unable to insert at position " << position << " list contains " << length << " elements" << std::endl;
        return;
    } else if (position == 0) {
        insertFront(value);
    } else if (position == length) {
        insertBack(value);
    }else {
        ListNode *temp = head;
        for (unsigned int i = 0; i < position - 1; i++) {
            temp = temp->next;
        }
        ListNode *newNode = new ListNode(value, temp->next, temp);
        temp->next->prev = newNode;
        temp->next = newNode;
        length++;
    }

}

void LinkedList::removeFront() {
    if (length == 0 || head == nullptr || tail == nullptr) {
        std::cout << "Invalid operation: list is empty" << std::endl;
        return;
    }
    if(head == tail){
        tail = nullptr;
        delete head;
        head = nullptr;
        length--;
        return;
    }
    ListNode *newNode = head->next;
    newNode->prev = nullptr;
    delete head;
    head = newNode;
    length--;
}

void LinkedList::removeBack() {
    if (length == 0 || head == nullptr || tail == nullptr) {
        std::cout << "Invalid operation: list is empty" << std::endl;
        return;
    }
    if(head == tail){
        head = nullptr;
        delete tail;
        length--;
        return;
    }
    ListNode *newNode = tail->prev;
    tail->prev->next = nullptr;
    delete tail;
    tail = newNode;
    length--;
}

void LinkedList::removeAt(unsigned int position) {
    if (position > length) {
        std::cout << "Position out of list range" << std::endl;
        return;
    }
    else if (position == 0) {
        removeFront();
    } else if (position == length) {
        removeBack();
    } else {
        ListNode *temp = head;
        for (unsigned long i = 0; i < position; i++) {
            temp = temp->next;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
        length--;
    }
}

int LinkedList::find(int value) {
    ListNode *temp = head;
    for (int i = 0; i < this->length; i++){
        if (temp->value == value){
            return i;
        }
        temp= temp->next;
    }
    return -1;
}

void LinkedList::print() {
    if (head == nullptr) {
        std::cout << "LIST IS EMPTY " << std::endl;
        return;
    }else {
        ListNode *temp = head;
        if (temp->prev == nullptr)
            std::cout << "nullptr -> ";
        for (int i = 0; i < this->length; i++) {
            std::cout << temp->value << " -> ";
            temp = temp->next;
        }
        if (temp == nullptr)
            std::cout << "nullptr" << std::endl;
    }
}

LinkedList::~LinkedList() {
    while(length != 0){
        removeFront();
        length--;
    }
}

int LinkedList::getLength() {
    return length;
}

ListNode* LinkedList::getElem(int pos) {
    ListNode *temp = head;
    for (int i = 0; i < pos; i++){
        temp = temp->next;
    }
    return temp;
}


