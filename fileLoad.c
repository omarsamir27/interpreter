//
// Created by omar on 5/25/20.
//

#include "fileLoad.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "BST.h"

void loadFile(char* filename,BST* bst,HEAP* heap){
    FILE * file=fopen(filename,"r");
    fseek(file,0,SEEK_END);
    rewind(file);
    char* expression;

    while (!feof(file)){
        expression=malloc(100);
        memset(expression,0,100);
        fgets(expression,100,file);
        expression[strcspn(expression,"\n")]='\0';
        checkValidExp(expression);
        char* LHS=strtok(expression,"=");
        char* RHS=(LHS+1);
        put(bst,LHS,yehia(bst,RHS));

    }
}
void removeSpaces(char* expression){
    int length=strlen(expression)+1;
    int Spaces=0;
        for(int i=0;i<length;++i){
            if(expression[i]==' ') Spaces++;}
        char tempstr[length-Spaces];
        for(int i=0,j=0;i<length;++i){
            if(expression[i]==' ');
            else {tempstr[j]=expression[i];j++;}
        }

        for(int i=0;i<length-Spaces-1;++i){
            expression[i]=tempstr[i];
        }
    expression[length-Spaces]='\0';
    expression=realloc(expression,strcspn(expression,"\0"));

}
void checkLeftSide(char* expression){
    if (!(isalpha(expression[0])||expression[0]=='_')) err(2,expression);
    for (int i=1;i<strpbrk(expression,"=")-expression;++i){
        if (!(isalnum(expression[i])||expression[i]=='_')) err(3,expression);
    }

}
void checkValidExp(char* expression){
    int equalSigns=0;
    for (int i = 0; expression[i]!='\0'; ++i) {
        if (expression[i]=='=') equalSigns++;
    }
    if (equalSigns!=1) err(1,expression);;
    //char* duplicate=strdup(expression);
    checkLeftSide(expression);
    removeSpaces(expression);
}
void err(int mode,char* expression){
    switch (mode) {
    case 1:
        fprintf(stderr,"Expression Contains multiple or No Equal Signs : %s",expression);
        exit(-1);

     case 2:
         fprintf(stderr,"Left hand side Illegal: Variable names can only start in letters or underscores: %s",expression);
         exit(-1);
      case 3:
            fprintf(stderr,"Left hand side Illegal: side must contain a single variable with no wildcards: %s",expression);
            exit(-1);
      default:
            fprintf(stderr,"FATAL ERROR!");
            exit(-1);
    }
}
