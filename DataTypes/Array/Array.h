//
// Created by Luka Mitrovic on 06/02/2022.
//

#ifndef SDIZO_ARRAY_H
#define SDIZO_ARRAY_H
#include <fstream>
#include <iostream>
#include <string>

class Array {
public:
    Array();
    explicit Array(int size);
    explicit Array(const std::string &filename);
    ~Array();

    void push(int index, int value);
    void push_back(int value);
    void push_front(int value);

    void pop(int index);
    void pop_back();
    void pop_front();

    void print();

    int search(int value);
    void modify(int index, int value);

    void copy(int* destination, const int* source, int numberOfElems);
    int getSize() const;
    int *at(int pos);

    int &operator[](int i);
private:
    int size;
    int *head;
};


#endif //SDIZO_ARRAY_H
