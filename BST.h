//
// Created by omar on 5/25/20.
//

#ifndef INTERPRETER_BST_H
#define INTERPRETER_BST_H
typedef struct Node{
    char* key;
    double value;
    struct Node* parent;
    struct Node* left;
    struct Node* right;
}Node;
typedef struct BST{
    Node* root;
    int count;
}BST ;
BST* initBST();
Node* createNode(char* key,double value);
void put(BST* tree,char* key,double value);
void delete(Node* root);
Node* search(Node* treeRoot,char* key);
double getKey(BST* bst,char* varName);
void InOrder(Node* root);
#endif //INTERPRETER_BST_H
