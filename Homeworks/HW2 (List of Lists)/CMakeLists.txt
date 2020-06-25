cmake_minimum_required(VERSION 3.15)
project(HW2)
set(CMAKE_CXX_STANDARD 14)
set(SOURCE_FILES main.cpp)
set(Header Header/TList.h Header/MList.h Header/Struct.h)
set(Source Source/MList.cpp Source/TList.cpp)
set(CLASSES  ${Source}  ${Header})
add_executable(HW2_B_ ${SOURCE_FILES} File.txt ${CLASSES})


