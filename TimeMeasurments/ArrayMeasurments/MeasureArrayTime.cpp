//
// Created by Luka Mitrovic on 18/04/2022.
//

#include "MeasureArrayTime.h"
#include <fstream>
#define PUSH_FRONT_FILE "/Users/lukamitrovic/Desktop/ArrResults/arr_push_front.txt"
#define PUSH_BACK_FILE "/Users/lukamitrovic/Desktop/ArrResults/arr_push_back.txt"
#define PUSH_FILE "/Users/lukamitrovic/Desktop/ArrResults/arr_push.txt"
#define POP_FRONT_FILE "/Users/lukamitrovic/Desktop/ArrResults/arr_pop_front.txt"
#define POP_BACK_FILE "/Users/lukamitrovic/Desktop/ArrResults/arr_pop_back.txt"
#define POP_FILE "/Users/lukamitrovic/Desktop/ArrResults/arr_pop.txt"
#define SEARCH_FILE "/Users/lukamitrovic/Desktop/ArrResults/arr_search.txt"


void MeasureArrayTime::measurePushFront(int arraySize, int measurmentsAmount) {
    testArray = new Array(arraySize);
    std::ofstream myfile;
    long averagetime = 0;
    myfile.open (PUSH_FRONT_FILE,std::fstream::app);
    for (int i = 0; i < measurmentsAmount; i++){
        int value = rand()%1000;
        time.measureStart();
        testArray->push_front(value);
        time.measureEnd();
        testArray->pop_front();
        averagetime += time.getTime();
    }
    myfile << "PushFront for " << arraySize << " elements and " << measurmentsAmount << " measurments : " << averagetime/measurmentsAmount << std::endl;
    myfile.close();
    delete testArray;
}
/* Funkja do zmierzania czasu wykonania funkcji dodania na początek tablicy
 * Zostaje stworzona tablica o rozmiaze @arraySize
 * do której @measurementsAmount razy dodajemy wartości
 * zamierzamy czas wykonania operacji
 * zapisujemy wynik w zmienniej averagetime żeby mieć w wyniku średni czas wykonania operacji
 * potem wykonujemy operację przeciwną żeby tablica się powróciła do stanu początkowego
 * wynik usredniony zapisujemy do pliku
 * */
void MeasureArrayTime::measurePushBack(int arraySize, int measurmentsAmount) {
    testArray = new Array(arraySize);
    std::ofstream myfile;
    long averagetime = 0;
    myfile.open (PUSH_BACK_FILE,std::fstream::app);
    for (int i = 0; i < measurmentsAmount; i++){
        int value = rand()%1000;
        time.measureStart();
        testArray->push_back(value);
        time.measureEnd();
        testArray->pop_back();
        averagetime += time.getTime();
    }
    myfile << "PushBack for " << arraySize << " elements and " << measurmentsAmount << " measurments : " << averagetime/measurmentsAmount << std::endl;
    myfile.close();
}

void MeasureArrayTime::measurePushAtAnyPos(int arraySize, int measurmentsAmount) {
    testArray = new Array(arraySize);
    std::ofstream myfile;
    long averagetime = 0;
    myfile.open (PUSH_FILE,std::fstream::app);
    for (int i = 0; i < measurmentsAmount; i++){
        int value = rand()%1000;
        time.measureStart();
        testArray->push(testArray->getSize()/2,value);
        time.measureEnd();
        testArray->pop(testArray->getSize()/2);
        averagetime += time.getTime();
    }
    myfile << "PushAnyPos for " << arraySize << " elements and " << measurmentsAmount << " measurments : " << averagetime/measurmentsAmount << std::endl;
    myfile.close();
    delete testArray;
}

void MeasureArrayTime::measurePopFront(int arraySize, int measurmentsAmount) {
    testArray = new Array();
    std::ofstream myfile;
    long averagetime = 0;
    myfile.open (POP_FRONT_FILE,std::fstream::app);
    for (int i = 0; i < arraySize; i++){
        int value = rand()%1000;
        testArray->push_back(value);
    }
    for (int i = 0; i < measurmentsAmount; i++){
        int value = rand()%1000;
        time.measureStart();
        testArray->pop_front();
        time.measureEnd();
        testArray->push_front(value);
        averagetime += time.getTime();
    }
    myfile << "PopFront for " << arraySize << " elements and " << measurmentsAmount << " measurments : " << averagetime/measurmentsAmount << std::endl;
    myfile.close();
    delete testArray;
}

void MeasureArrayTime::measurePopBack(int arraySize, int measurmentsAmount) {
    testArray = new Array();
    std::ofstream myfile;
    long averagetime = 0;
    myfile.open (POP_BACK_FILE,std::fstream::app);
    for (int i = 0; i < arraySize; i++){
        int value = rand()%1000;
        testArray->push_back(value);
    }
    for (int i = 0; i < measurmentsAmount; i++){
        int value = rand()%1000;
        time.measureStart();
        testArray->pop_back();
        time.measureEnd();
        testArray->push_back(value);
        averagetime += time.getTime();
    }
    myfile << "PopBack for " << arraySize << " elements and " << measurmentsAmount << " measurments : " << averagetime/measurmentsAmount << std::endl;
    myfile.close();
    delete testArray;
}

void MeasureArrayTime::measurePopAtAnyPos(int arraySize, int measurmentsAmount) {
    testArray = new Array();
    std::ofstream myfile;
    long averagetime = 0;
    myfile.open (POP_FILE,std::fstream::app);
    for (int i = 0; i < arraySize; i++){
        int value = rand()%1000;
        testArray->push_back(value);
    }
    for (int i = 0; i < measurmentsAmount; i++){
        int value = rand()%1000;
        time.measureStart();
        testArray->pop(testArray->getSize()/2);
        time.measureEnd();
        testArray->push(testArray->getSize()/2,value);
        averagetime += time.getTime();
    }
    myfile << "PopAnyPos for " << arraySize << " elements and " << measurmentsAmount << " measurments : " << averagetime/measurmentsAmount << std::endl;
    myfile.close();
    delete testArray;
}

void MeasureArrayTime::measureSearch(int arraySize, int measurmentsAmount) {
    testArray = new Array();
    std::ofstream myfile;
    long averagetime = 0;
    int searchVal = 0;
    myfile.open (SEARCH_FILE,std::fstream::app);
    for (int i = 0; i < arraySize; i++){
        int value = rand()%1000;
        testArray->push_back(value);
        if (i == arraySize - 2) {
            searchVal = value;
        }
    }
    for (int i = 0; i < measurmentsAmount; i++){
        time.measureStart();
        testArray->search(searchVal);
        time.measureEnd();
        averagetime += time.getTime();
    }
    myfile << "Search for " << arraySize << " elements and " << measurmentsAmount << " measurments : " << averagetime/measurmentsAmount << std::endl;
    myfile.close();
    delete testArray;
}

void MeasureArrayTime::executeAllTests() {
    for (int i = 10; i <= 10000; i *= 10){
        measurePushFront(i,50);
        measurePushBack(i,50);
        measurePushAtAnyPos(i,50);
        measurePopFront(i,50);
        measurePopBack(i,50);
        measurePopAtAnyPos(i,50);
        measureSearch(i,50);
    }
    for (int i = 20000; i <= 60000; i *= 2){
        measurePushFront(i,50);
        measurePushBack(i,50);
        measurePushAtAnyPos(i,50);
        measurePopFront(i,50);
        measurePopBack(i,50);
        measurePopAtAnyPos(i,50);
        measureSearch(i,50);
    }
    measurePushFront(100000,50);
    measurePushBack(100000,50);
    measurePushAtAnyPos(100000,50);
    measurePopFront(100000,50);
    measurePopBack(100000,50);
    measurePopAtAnyPos(100000,50);
    measureSearch(100000,50);
}
