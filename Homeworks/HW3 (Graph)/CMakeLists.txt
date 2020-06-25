cmake_minimum_required(VERSION 3.15)
project(HW3)

set(CMAKE_CXX_STANDARD 14)
set(Graph Graph.cpp Graph.h)
add_executable(HW3_B main.cpp ${Graph})