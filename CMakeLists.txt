cmake_minimum_required(VERSION 3.6)
project(Paalg)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Sorting/ArraySorting.cpp Sorting/ArraySorting.h Tree/BinarySearchTree.cpp Tree/BinarySearchTree.h Tree/BTree.cpp Tree/BTree.h)
add_executable(Paalg ${SOURCE_FILES} Sorting/ArraySorting.cpp Sorting/ArraySorting.h Tree/BTree.cpp Tree/BTree.h)