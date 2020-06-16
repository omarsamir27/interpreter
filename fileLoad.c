#include "fileLoad.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "BST.h"
#include "stacks.h"
#include "evaluator.h"
#include "heaps.h"
extern char* case_mode;
heapnode* loadFile(char* filename,BST* bst) {
    FILE *file = fopen(filename, "r");
    if(!file){
        fprintf(stderr,"File Does Not Exist");
        exit(-1);
    }
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);
    char *expression;

    while (ftell(file) != file_size) {
        expression = malloc(100);
        memset(expression, 0, 100);
        fgets(expression, 100, file);
        if(!strcasecmp(expression,"\n"))
            break;
        expression[strcspn(expression, "\n")] = '\0';
        checkValidExp(expression);
        if (case_mode == NULL)
            goto insensitive;
        if (strcasecmp(case_mode, "case") != 0) {
            for (int i = 0; expression[i] != '\0'; ++i) {
                expression[i] = (char) toupper(expression[i]);
            }
        }

        insensitive:
        {
            char *LHS = strtok(expression, "=");
            char *RHS = (LHS + strcspn(LHS,"=")+1);
            put(bst, LHS, rightside_evaluation(bst, RHS));
        }
    }
    heapnode *ValueHeap = initHeap();
    fclose(file);
    return heapSort(ValueHeap);

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
    expression[length-Spaces-1]='\0';
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
    removeSpaces(expression);
    checkLeftSide(expression);

}
void err(int mode,char* expression){
    switch (mode) {
        case 1:
        fprintf(stderr,"Expression Contains multiple or No Equal Signs : %s",expression);
        exit(-1);
        case 2:
         fprintf(stderr,"Left hand side Illegal: Variable names can only start in letters or underscores: %s \n",expression);
         exit(-1);
        case 3:
            fprintf(stderr,"Left hand side Illegal: side must contain a single variable with no wildcards: %s \n",expression);
            exit(-1);
        case 4:
            fprintf(stderr,"Right hand side Illegal: Unbalanced Parentheses in %s \n",expression);
            exit(1);
        case 5:
            fprintf(stderr,"Right hand side Illegal: Operator at Extremities in %s \n",expression);
            exit(1);
        case 6:
            fprintf(stderr,"Right hand side Illegal: Operator Overload in %s \n",expression);
            exit(1);
        case 7:
            fprintf(stderr,"Right hand side Illegal: Void Parentheses in %s \n",expression);
            exit(1);
        case 8:
            fprintf(stderr,"Right hand side Illegal: Undefined Character in %s \n",expression);
            exit(1);
        case 9:
            fprintf(stderr,"Right hand side Not Found");
            exit(1);
        case 10:
            fprintf(stderr,"Right hand side Illegal: Radix Point Error in %s \n",expression);
            exit(1);
        case 11:
            fprintf(stderr,"Right hand side Illegal: Illegal Variable Name in %s \n",expression);
            exit(1);
      default:
            fprintf(stderr,"FATAL ERROR!");
            exit(-1);
    }
}

