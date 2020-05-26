//
// Created by omar on 5/25/20.
//

#include "BST.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
Node* createNode(char* key,double value) {
    Node *node = malloc(sizeof(Node));
    node->key = strdup(key);
    free(key);
    node->value = value;
    node->parent = node->right = node->left = NULL;
    return node;
}
BST* initBST(void) {
    BST *tree = malloc(sizeof(BST));
    tree->root = NULL;
    tree->count = 0;
    return tree;
}
Node* search(Node* treeRoot,char* varName) {
    Node *current = treeRoot;
    Node *parent = current;
    while ((current != NULL) && (strcasecmp(current->key, varName) != 0)) {
        if (strcasecmp(current->key, varName) > 0) {
            parent = current;
            current = current->left;
        } else {
            parent = current;
            current = current->right;
        }
    }
    if (!current) return parent;
    return current;
}
double getKey(BST* bst,char* varName){
    Node* node=search(bst->root,varName);
    if (!strcasecmp(varName,node->key)) return node->value;
    return DBL_MAX;
}
void put(BST *tree,char* key,double value){
    Node* check=search(tree->root,key);
    if(!strcasecmp(key,check->key)){
        check->value=value;
    }
    Node* toAdd=createNode(key,value);
    if (!(tree->root)){
        tree->root=toAdd;
        (tree->count)++;
        return;
    }
    Node* current=tree->root;
    Node* parent=current;
    while (current!=NULL){
        if (strcasecmp(current->key,toAdd->key)>0){
            parent=current;
            current=current->left;
            continue;
        } else{
            parent=current;
            current=current->right;
            continue;
        }
    }
    current=toAdd;
    current->parent=parent;
    if (strcasecmp(parent->key,current->key)>0)
        parent->left=current;
    else
        parent->right=current;
    (tree->count)++;
}
void InOrder(Node* root){
    if (!root) return;
    InOrder(root->left);
    printf("%s = %.3f  ",root->key,root->value);
    InOrder(root->right);
}