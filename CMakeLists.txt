cmake_minimum_required(VERSION 3.15)
project(BinarySearch)

set(CMAKE_CXX_STANDARD 14)

add_executable(BinarySearch main.cpp BinarySearch.h Node.cpp Node.h BinaryTree.cpp BinaryTree.h)