#ifndef INTERPRETER_FILELOAD_H
#define INTERPRETER_FILELOAD_H
#include "BST.h"
#include "heaps.h"
heapnode* loadFile(char* filename,BST* bst);
void removeSpaces(char* expression);
void checkLeftSide(char* leftSide);
void checkValidExp(char* expression);
void err(int mode,char* expression);

#endif //INTERPRETER_FILELOAD_H
