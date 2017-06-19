cmake_minimum_required(VERSION 3.3)
project(hw7_requirements)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    HW7_Requirements.pdf
    main.cpp
    Makefile
    MaxHeap.h
    numbers.txt
    numbers_small.txt)

add_executable(hw7_requirements ${SOURCE_FILES})