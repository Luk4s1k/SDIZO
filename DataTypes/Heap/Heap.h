//
// Created by Luka Mitrovic on 26/03/2022.
//

#ifndef SDIZO_HEAP_H
#define SDIZO_HEAP_H

#include "../Array/Array.h"
#include "../LinkedList/LinkedList.h"

class Heap {
    Array heapArray;
public:
    Heap();
    Heap(std::string filename);
    ~Heap();

    void heapifyFromStart(int index);
    void heapifyFromEnd(int index);

    void addElement(int value);
    int extractRoot();

    int getRootValue();
    void printAsArray ();
    void printAsTree();
    void swap(int a, int b);

    int getParent(unsigned int index);
    int getLeftChild(unsigned int index);
    int getRightChild(unsigned int index);

    bool search(int startPos, int value);


    void printer (unsigned index, unsigned mlength);
    void print_tree ();
};


#endif //SDIZO_HEAP_H
