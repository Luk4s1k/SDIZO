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
     LinkedList(int size);
     LinkedList( std::string filename);
     ~LinkedList();

     void insertFront(int value);
     void insertBack(int value);
     void insertAt(unsigned int position, int value);

     void removeFront();
     void removeBack();
     void removeAt(unsigned int position);

     int getLength();
     ListNode* getElem(int pos);

     int find(int value);

     void print();


};


#endif //SDIZO_LINKEDLIST_H
