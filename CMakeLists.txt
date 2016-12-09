cmake_minimum_required(VERSION 3.6)
project(Paalg)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Sorting/ArraySorting.cpp Sorting/ArraySorting.h Tests/ArrayUtil.cpp Tests/ArrayUtil.h Tree/TreeNode.h Tree/BinarySearchTree.h Tree/BinarySearchTree.cpp BTree/BTreeNode.h BTree/BTree.h)
add_executable(Paalg ${SOURCE_FILES} Sorting/ArraySorting.cpp Sorting/ArraySorting.h)