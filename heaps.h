//
// Created by omar on 5/28/20.
//

#ifndef INTERPRETER_HEAPS_H
#define INTERPRETER_HEAPS_H

#include "BST.h"

typedef struct heapnode{
    char key[30];
    double value;
}heapnode;
void fillheap(heapnode* heap,Node * node,int i);
void swap(heapnode * x,heapnode * y);
void heapify(heapnode * heap, int size, int i);
heapnode* heapSort();
void printHeap(heapnode* heap);

#endif //INTERPRETER_HEAPS_H
