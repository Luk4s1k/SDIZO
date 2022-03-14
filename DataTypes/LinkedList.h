//
// Created by Luka Mitrovic on 14/03/2022.
//

#ifndef SDIZO_LINKEDLIST_H
#define SDIZO_LINKEDLIST_H

#include <string>
#include "ListNode.h"
class Node {
public:
    Node(){
        next = nullptr;
        prev = nullptr;
        value = 0;
    }
    Node(int value):value(value){
        next = nullptr;
        prev = nullptr;
    }
private:
    int *next;
    int *prev;
    int value;
};
class LinkedList {
private:
     Node *head;
     Node *tail;
     int length;
public:
     LinkedList();
     LinkedList( std::string filename);

     void insertFront(int value);
     void insertBack(int value);
     void insertAfter(Node node, int value);

     Node* getNodeAtPos(int pos);

     void removeFront();
     void removeBack();
     void removeAfter();

     void find(int value);

     void print();


};


#endif //SDIZO_LINKEDLIST_H
