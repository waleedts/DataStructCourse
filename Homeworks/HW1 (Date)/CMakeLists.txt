cmake_minimum_required(VERSION 3.15)
project(HW1)

set(CMAKE_CXX_STANDARD 14)
set(Date Date.cpp Date.h)
add_executable(HW1 main.cpp ${Date})