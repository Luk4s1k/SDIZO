cmake_minimum_required(VERSION 3.21)
project(SDIZO)

set(CMAKE_CXX_STANDARD 20)

add_executable(SDIZO main.cpp DataTypes/Array.cpp DataTypes/Array.h Menu.cpp Menu.h)
