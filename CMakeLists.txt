cmake_minimum_required(VERSION 3.21)
project(SDIZO)

set(CMAKE_CXX_STANDARD 20)

add_executable(SDIZO main.cpp DataTypes/Array/Array.cpp DataTypes/Array/Array.h Menu/Menu.cpp Menu/Menu.h DataTypes/LinkedList/LinkedList.cpp DataTypes/LinkedList/LinkedList.h DataTypes/LinkedList/ListNode.h DataTypes/Heap/Heap.cpp DataTypes/Heap/Heap.h)
