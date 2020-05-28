//
// Created by omar on 5/28/20.
//

#include "heaps.h"
#include "BST.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
extern BST* global_tree;

void fillheap(heapnode* heap,Node * node)
{
    static int i=0;
    if (node == NULL)
        return;
    fillheap(heap,node->left);
    heap[i].value=node->value;
    strcpy(heap[i].key,node->key);
    i++;
    fillheap(heap,node->right);
}
void swap(heapnode * x,heapnode * y)
{
    heapnode  temp;
    strcpy(temp.key,(*x).key);
    temp.value=(*x).value;
    strcpy((*x).key,(*y).key);
    (*x).value=(*y).value;
    strcpy((*y).key,temp.key);
    (*y).value=temp.value;
}
void heapify(heapnode * heap, int size, int i)
{
    int root = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if (l < size && heap[l].value > heap[root].value)
        root = l;
    if (r < size&& heap[r].value > heap[root].value)
        root = r;
    if (root != i)
    {
        swap(&heap[i],&heap[root]);
        heapify(heap,size, root);
    }
}
heapnode* initHeap(){
    heapnode* toReturn=malloc(sizeof(heapnode)*global_tree->count);
    return toReturn;
}
heapnode* heapSort(heapnode* heap)
{
    fillheap(heap,global_tree->root);
    for (int i = global_tree->count / 2 - 1; i >= 0; i--)
        heapify(heap,global_tree->count, i);
    for (int i=global_tree->count-1; i>0; i--)
    {
        swap(&heap[0],&heap[i]);
        heapify(heap,i,0);
    }
    return heap;
}
void printHeap(heapnode* heap){
    for (int i=0;i<global_tree->count;i++){
        printf("%s = %.3f \n",heap[i].key,heap[i].value);
    }
}