cmake_minimum_required(VERSION 3.6)
project(Hw8_Requirements_std)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
    BSTree.cpp
    BSTree.h
    HashTable.cpp
    HashTable.h
    HW8_Requirements.pdf
    login.cpp
    main.cpp
    Makefile
    password.dat
    test10.cpp)

add_executable(Hw8_Requirements_std ${SOURCE_FILES})