cmake_minimum_required(VERSION 3.3)
project(hw1_requirements)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    HW1_Problems.docx
    HW1_Requirements.pdf
    input.in
    KthLargest.h
    kthsearch
    main.cpp
    main.o
    Makefile
    ~\$1_Problems.docx)

add_executable(hw1_requirements ${SOURCE_FILES})