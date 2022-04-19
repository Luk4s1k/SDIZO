cmake_minimum_required(VERSION 3.21)
project(SDIZO)

set(CMAKE_CXX_STANDARD 20)

add_executable(SDIZO main.cpp DataTypes/Array/Array.cpp DataTypes/Array/Array.h Menu/ArrayMenu/ArrayMenu.cpp Menu/ArrayMenu/ArrayMenu.h DataTypes/LinkedList/LinkedList.cpp DataTypes/LinkedList/LinkedList.h DataTypes/LinkedList/ListNode.h DataTypes/Heap/Heap.cpp DataTypes/Heap/Heap.h Menu/ListMenu/LinkedListMenu.cpp Menu/ListMenu/LinkedListMenu.h Menu/HeapMenu/HeapMenu.cpp Menu/HeapMenu/HeapMenu.h Menu/MainMenu/MainMenu.cpp Menu/MainMenu/MainMenu.h TimeMeasurments/MeasureTime.cpp TimeMeasurments/MeasureTime.h TimeMeasurments/ArrayMeasurments/MeasureArrayTime.cpp TimeMeasurments/ArrayMeasurments/MeasureArrayTime.h TimeMeasurments/ListMeasurments/MeasureListTime.cpp TimeMeasurments/ListMeasurments/MeasureListTime.h TimeMeasurments/HeapMeasurments/MeasureHeapTime.cpp TimeMeasurments/HeapMeasurments/MeasureHeapTime.h)
