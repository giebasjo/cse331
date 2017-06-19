cmake_minimum_required(VERSION 3.3)
project(Hw6_Requirements)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    HW6_Requirements.pdf
    Library.h
    main.cpp
    Makefile)

add_executable(Hw6_Requirements ${SOURCE_FILES})