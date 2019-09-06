cmake_minimum_required(VERSION 3.14)
project(DLL)

set(CMAKE_CXX_STANDARD 14)

add_executable(DLL doubleLinkedList.cpp doubleLinkedList.h main.cpp)