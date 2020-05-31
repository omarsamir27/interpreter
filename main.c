//
// Created by omar on 5/28/20.
//
#include <stdio.h>
#include "BST.h"
#include "fileLoad.h"
#include <stdlib.h>
#include <string.h>
#include "heaps.h"
char* case_mode;
int main(int argc , char* argv[]){
    case_mode=argv[1];
    BST* variableNameTree= initBST();
    char* filename=malloc(255);
    do{
        memset(filename,0,255);
        puts("Please Write Absolute File path for Source");
        fgets(filename,255,stdin);
        filename[strcspn(filename,"\n")]='\0';
        heapnode* ValueHeap =loadFile(filename,variableNameTree);
        puts("Sorting by Key");
        InOrder(variableNameTree->root);
        puts("Sorting By Value");
        printHeap(ValueHeap);
        /*CLEAR BST AND HEAP*/
    }while (strcasecmp(filename,"")!=0)



}
