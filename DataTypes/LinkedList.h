//
// Created by Luka Mitrovic on 14/03/2022.
//

#ifndef SDIZO_LINKEDLIST_H
#define SDIZO_LINKEDLIST_H

#include <string>
#include "ListNode.h"

class LinkedList {
private:
     ListNode *head;
     ListNode *tail;
     int length;
public:
     LinkedList();
     LinkedList( std::string filename);

     void insertFront(int value);
     void insertBack(int value);
     void insertAfter(ListNode node, int value);

     ListNode* getNodeAtPos(int pos);

     void removeFront();
     void removeBack();
     void removeAfter();

     void find(int value);

     void print();


};


#endif //SDIZO_LINKEDLIST_H
