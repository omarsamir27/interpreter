#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<ctype.h>
#include<math.h>
typedef union
{
    double dData;
    char  cData;
} Item;

typedef struct
{
    Item* data;
    struct Stack * next;

} Stack;


Stack * initialize()
{
    Stack* newStack=malloc(sizeof(Stack));
    newStack->data=malloc(sizeof(Item));
    return newStack;
}

int isEmpty(Stack *s)
{
    return s==NULL;

}

Item top(Stack **s)
{
    return *((*s)->data);
}
void destroy(Stack **s)
{
    while(*s!=NULL)
    Stack* temp;
    temp=*s;
    *s = (*s)->next;
    free(temp->data);
    free( temp );
}
Item  pop(Stack **s)
{
    Stack* temp;
    Item popVal;
    popVal= *(( *s )->data);
    temp=*s;
    *s = (*s)->next;
    free(temp->data);
    free( temp );
    return popVal;
}

void push(Stack **s, Item* val)
{
    Stack* newStack= initialize();
    *(newStack->data)=*val;
    newStack->next = *s;
    *s = newStack;
}
int precdOpr(char opr)
{
    if(opr=='+'||opr=='-')
    return 0 ;
    else if(opr=='/'||opr=='*')
    return 1;
    else if(opr=='^')
    return 2;
    else
    return -1;

}
void infixToPostfix(char* infix, char* postfix)
{
char* token= strtok(infix," ");
    Item temp;char tempOpr[2];tempOpr[1]='\0';
    Stack *head=NULL;
    while(token!= NULL)
    {
        if(isalpha(token[0])||isdigit(token[0])||token[0]=='_')
        {
           strcat(postfix,token);
           strcat(postfix," ");
        }
        else if(token[0]=='(')
        {
            temp.cData=token[0];
            push(&head,&temp);
        }
        else if (token[0]==')')
        { temp= pop(&head);

            while(temp.cData!='(')
            {

                token[0]=temp.cData;
                strcat(postfix,token);
                strcat(postfix," ");
                temp=pop(&head);

            }
        }
        else
        {
            if(!isEmpty(head))
            temp=top(&head);
            while(!isEmpty(head)&&(precdOpr(token[0])<=precdOpr(temp.cData)))
            {
                tempOpr[0]=temp.cData;
                strcat(postfix,tempOpr);
                strcat(postfix," ");
                pop(&head);
                if(!isEmpty(head))
                temp=top(&head);

            }
            temp.cData=token[0];
            push(&head,&temp);
        }
        token=strtok(NULL," ");
    destroy(&head);
}

while(!isEmpty(head))
    {
        temp=pop(&head);
        tempOpr[0]=temp.cData;
        strcat(postfix,tempOpr);
        strcat(postfix," ");
    }

    postfix[strlen(postfix)-1]='\0';
}
void operatorHandle(char opr,Stack**head)
{
    Item op1=pop(&head);
    Item op2=pop(&head);
    switch(opr){
    case '+' :
       op1.dData=op2.dData+op1.dData;
       push(&head,&op1);
       break;
    case '-' :
      op1.dData=op2.dData-op1.dData;
       push(&head,&op1);
          break;
    case '/' :
      op1.dData=op2.dData/op1.dData;
       push(&head,&op1);
          break;
    case '*' :
        op1.dData=op2.dData*op1.dData;
       push(&head,&op1);
          break;
    case '^' :
   op1.dData=pow(op2.dData,op1.dData);
       push(&head,&op1);
          break;
}}
double evaluatePostfix(char* postfix)
{
    char* token= strtok(postfix," ");
    Item temp;
    Stack *head=NULL;
    while(token!= NULL)
    {
        if(isdigit(token[0]))
        {
            temp.dData= atof(token);
            push(&head,&temp);
        }
        else if (isalpha(token[0])||token[0]=='_')
        {
         // temp.dData= getkey(token);
            push(&head,&temp);
        }
        else
           {operatorHandle(*token,&head);}

        token=strtok(NULL," ");
    }
    temp=pop(&head);
    destroy(&head);
    return temp.dData;

}

void replaceNewLineBySpace(char *s)
{
    char *s1 = s;
    while((s1 = strstr(s1, "\n")) != NULL)
        *s1 = ' ';
}

int main(int argc, char**argv)
{
    char* infixExpr = malloc(sizeof(char)*256);
    char* postfixExpr = malloc(sizeof(char)*256);
    memset(postfixExpr,0,256);
    printf("Enter an expression you want to evaluate or Ctrl+Z to exit: ");
    while(fgets(infixExpr, 255, stdin) != NULL)
    {
        replaceNewLineBySpace(infixExpr);
        infixToPostfix(infixExpr, postfixExpr);
        printf("Postfix : %s\n", postfixExpr);
        double result = evaluatePostfix(postfixExpr);
        printf("Result: %.3f\n\n", result);
        printf("Enter an expression you want to evaluate or Ctrl+Z to exit: ");
    }
    return 0;
}
