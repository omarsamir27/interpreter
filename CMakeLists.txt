cmake_minimum_required(VERSION 3.16)
project(interpreter C)

set(CMAKE_C_STANDARD 11)

add_executable(interpreter  fileLoad.h fileLoad.c fileLoad.h BST.c BST.h evaluator.c evaluator.h stacks.c stacks.h main.c heaps.c heaps.h)
target_link_libraries(interpreter m)