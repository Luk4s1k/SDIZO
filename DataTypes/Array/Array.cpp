//
// Created by Luka Mitrovic on 06/02/2022.
//

#include "Array.h"

Array::Array() {
    size = 0;
    head = new int[1];
}
Array::Array(int size) {
    this->size = size;
    head = new int[1];
}

Array::Array(std::string filename) {
    std::ifstream file;
    int arraySizeFromFile;
    int readVal, i;
    file.open(filename);
    if(file.is_open()){
        file >> arraySizeFromFile;
        head = new int[arraySizeFromFile];
        while(file.good()){
            file >> readVal;
            push(i,readVal);
            i++;
        }
    }
    if (size != arraySizeFromFile) std::cout << "INVALID SIZE OF ARRAY PROVIDED IN FILE" << std::endl;
    file.close();
}

void Array::push(int index, int value) {
    if (index > size || index < 0){
        std::cout << "Provided index out of range " << std::endl;
        return;
    }
    else if (size == 0) {
        head[0] = value;
        size++;
    }
    else {
        if (index == 0){
            push_front(value);
        } else if (index == size - 1) {
            push_back(value);
        } else {
            int *newArr = new int[size + 1];
            copy(newArr, head, index);
            copy(&newArr[index + 1], &head[index], size - index);
            newArr[index] = value;
            delete[] head;
            head = newArr;
            size++;
        }
    }
}

void Array::push_back(int value) {
    if (size == 0) {
        head[0] = value;
        size++;
    }
    else {
        int *newArr = new int[size + 1];
        copy(newArr, head, size);
        newArr[size] = value;
        delete [] head;
        head = newArr;
        size++;
    }
}

void Array::push_front(int value) {
    if (size == 0) {
        head[0] = value;
        size++;
    }
    else {
        int *newArr = new int[size];
        copy(&newArr[1], head, size);
        newArr[0] = value;
        delete [] head;
        head = newArr;
        size++;
    }
}

void Array::pop(int index) {
    if (size == 0) {
        return;
    }
    else if (index > size || index < 0){
        std::cout << "Provided index out of range " << std::endl;
        return;
    }
    else {
        int *newArr = new int[size-1];
        copy(newArr, head, index);
        copy(&newArr[index], &head[index+1], size - index );
        delete[] head;
        head = newArr;
        --size;
    }
}

void Array::pop_back() {
    if (size == 0) {
        return;
    }
    else {
        int *newArr = new int[size-1];
        copy(newArr, head, size - 1 );
        delete[] head;
        head = newArr;
        --size;
    }

}

void Array::pop_front() {
    if (size == 0) {
        return;
    }
    else {
        int *newArr = new int[size-1];
        copy(newArr, &head[1], size - 1 );
        delete[] head;
        head = newArr;
        --size;
    }
}

void Array::print() {
    if (size == 0 ){
        std::cout << "EMPTY ARRAY" << std::endl;
        return;
    }
    for (int i = 0; i < size; i++){
        std::cout << head[i] << " ";
    }
    std::cout << std::endl;
}

int Array::getSize() {
    return size;
}

int *Array::getPointer(int pos) {
    return &head[pos];
}

Array::~Array() {
    delete [] head;
}

void Array::copy(int *destination, int *source, int numberOfElems) {
    for (int i = 0; i < numberOfElems; i++) {
        destination[i] = source[i];
    }

}

void Array::rprint() {
    if (size == 0 ){
        std::cout << "EMPTY ARRAY" << std::endl;
        return;
    }
    for (int i = size - 1 ; i >= 0; i--){
        std::cout << head[i] << " ";
    }
    std::cout << std::endl;

}

int Array::search(int value) {
    for (int i = 0; i < size; i++){
        if (head[i] == value) return i;
    }
    return -1;
}

void Array::modify(int index, int value) {
    head[index] = value;
}

int &Array::operator[](int i) {
    if( i > size ) {
        std::cout << "Index out of range" << std::endl;
        return head[0];
    }

    return head[i];
}

int *Array::at(int pos) {
    return &head[pos];
}






