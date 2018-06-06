cmake_minimum_required(VERSION 3.9)
project(BTree)

set(CMAKE_CXX_STANDARD 11)



add_executable(BTree main.cpp
        node.h
        tree.h
        Key.cpp Key.h)
