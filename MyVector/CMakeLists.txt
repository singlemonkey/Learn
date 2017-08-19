cmake_minimum_required(VERSION 3.8)
project(MyVector)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Fib.h MyVector.cpp MyVector.h)
add_executable(MyVector ${SOURCE_FILES})