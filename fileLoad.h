//
// Created by omar on 5/25/20.
//

#ifndef INTERPRETER_FILELOAD_H
#define INTERPRETER_FILELOAD_H
#include "BST.h"
#include "heaps.h"
void loadFile(char* filename,BST* bst,heapnode* heap);
void removeSpaces(char* expression);
void checkLeftSide(char* leftSide);
void checkValidExp(char* expression);
void err(int mode,char* expression);

#endif //INTERPRETER_FILELOAD_H
