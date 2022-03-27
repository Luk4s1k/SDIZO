//
// Created by Luka Mitrovic on 26/03/2022.
//

#include "Heap.h"
#include<sstream>
#include<string>
#include<cmath>
#include<iomanip>
#include<vector> // used only in printAsTreeFunction

Heap::Heap() {
    heapArray = Array();
}

Heap::Heap(std::string filename) {
    heapArray = Array(filename);
}

void Heap::heapifyFromStart(int index) {
    int left = getLeftChild(index);
    int right = getRightChild(index);

    int largest = index;

    if (left < heapArray.getSize() && heapArray[left] > heapArray[index]) {
        largest = left;
    }

    if (right < heapArray.getSize() && heapArray[right] > heapArray[largest]) {
        largest = right;
    }

    if (largest != index)
    {
        swap(index, largest);
        heapifyFromStart(largest);
    }
}

void Heap::heapifyFromEnd(int index) {
    if (index && heapArray[getParent(index)] < heapArray[index])
    {
        swap(index, getParent(index));

        heapifyFromEnd(getParent(index));
    }
}

void Heap::addElement(int value) {
    heapArray.push_front(value);
    int index = heapArray.getSize() - 1;
    heapifyFromEnd(index);
}

int Heap::extractRoot() {
    if (heapArray.getSize() == 0)
    {
        std::cout << "Heap is already empty" << std::endl;
        return -1;
    }
    int temp = heapArray[0];
    heapArray.pop_front();
    heapifyFromStart(0);
    return temp;
}

int Heap::getRootValue() {
    return heapArray[0];
}

void Heap::printAsArray() {
    heapArray.print();
}
std::string do_padding (unsigned index, unsigned mlength){
    std::string padding;
    if (int((index-1)/2) != 0){
        return (int((index-1)/2) % 2 == 0) ?
               (do_padding(int((index-1)/2),mlength) + std::string(mlength+4,' ') + " ")  :
               (do_padding(int((index-1)/2),mlength) + std::string(mlength+3,' ') + " |") ;
    }
    return padding;
}


void Heap::printer (unsigned index, unsigned mlength){
    auto last = heapArray.getSize() - 1 ;
    auto  left = 2 * index + 1 ;
    auto  right = 2 * index + 2 ;
    std::cout << " " << heapArray[index] << " ";
    if (left <= last){
        auto llength = std::to_string(heapArray[left]).size();
        std::cout << "---" << std::string(mlength - llength,'-');
        printer(left,mlength);
        if (right <= last) {
            auto rlength = std::to_string(heapArray[right]).size();
            std::cout << "\n" << do_padding(right,mlength) << std::string(mlength+ 3,' ') << " | ";
            std::cout << "\n" << do_padding(right,mlength) << std::string(mlength+ 3,' ') << " └" <<
                      std::string(mlength - rlength,'-');
            printer(right,mlength);
        }
    }
}


void Heap::print_tree (){
    unsigned mlength = 0;
    for (int i = 0; i < heapArray.getSize(); i++){
        auto clength = std::to_string(heapArray[i]).size();
        if (clength > mlength) {
            mlength = std::to_string(heapArray[i]).size();
        }
    }
    std::cout <<  std::string(mlength- std::to_string(heapArray[0]).size(),' ');
    printer(0,mlength);
}

int Heap::getParent(unsigned int index) {
    return (index - 1) / 2;
}

int Heap::getLeftChild(unsigned int index) {
    return (2 * index + 1);
}

int Heap::getRightChild(unsigned int index) {
    return (2 * index + 2);
}


void Heap::swap(int a, int b)
{
    int temp = heapArray[a];
    heapArray[a] = heapArray[b];
    heapArray[b] = temp;
}

bool Heap::search(int startPos, int value) {
    unsigned int left = 2 * startPos + 1;
    unsigned int right = 2 * startPos + 1;
    if(heapArray[startPos] == value){
        return true;
    }
    if(left > heapArray.getSize()){
        return false;
    }
    bool isFounded = search(left, value);
    if (isFounded){
        return true;
    }
    if(right > heapArray.getSize()){
        return false;
    }
    return search(right, value);
}

Heap::~Heap() {

}
