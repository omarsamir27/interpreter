#ifndef INTERPRETER_HEAPS_H
#define INTERPRETER_HEAPS_H

#include "BST.h"

typedef struct heapnode{
    char key[30];
    double value;
}heapnode;
void fillheap(heapnode* heap,Node * node);
void swap(heapnode * x,heapnode * y);
void heapify(heapnode * heap, int size, int i);
heapnode* heapSort(heapnode* heap);
void printHeap(heapnode* heap);
heapnode* initHeap();

#endif //INTERPRETER_HEAPS_H
