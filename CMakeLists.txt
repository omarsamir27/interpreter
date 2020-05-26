cmake_minimum_required(VERSION 3.16)
project(interpreter C)

set(CMAKE_C_STANDARD 11)

add_executable(interpreter main.c fileLoad.h fileLoad.c fileLoad.h BST.c BST.h)