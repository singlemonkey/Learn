cmake_minimum_required(VERSION 3.7)
project(BubbleSort)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp print.cpp print.h bubble.cpp)
add_executable(BubbleSort ${SOURCE_FILES} print.h print.h)