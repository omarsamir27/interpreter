#include <stdio.h>
#include "BST.h"
#include "fileLoad.h"
#include <stdlib.h>
#include <string.h>
#include "heaps.h"
char* case_mode;
int main(int argc , char* argv[]){
    case_mode=argv[1];
    BST* variableNameTree;
    heapnode* ValueHeap;
    char* filename=malloc(255);
    do{
        variableNameTree= initBST();
        memset(filename,0,255);
        puts("Please Write Absolute File path for Source");
        fgets(filename,255,stdin);
        filename[strcspn(filename,"\n")]='\0';
        ValueHeap =loadFile(filename,variableNameTree);
        puts("Sorting by Key");
        InOrder(variableNameTree->root);
        puts("Sorting By Value");
        printHeap(ValueHeap);
        /*CLEAR BST AND HEAP*/
        free(ValueHeap);
        clear(variableNameTree);
    }while (strcasecmp(filename,"")!=0);



}
