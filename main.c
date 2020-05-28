//
// Created by omar on 5/28/20.
//
#include <stdio.h>
#include "BST.h"
#include "fileLoad.h"
#include <stdlib.h>

int main(){
    BST* variableNameTree= initBST();
    loadFile("test",variableNameTree);
    InOrder(variableNameTree->root);
}
