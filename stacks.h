#ifndef INTERPRETER_STACKS_H
#define INTERPRETER_STACKS_H
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
Stack * initialize();
int isEmpty(Stack *s);
Item top(Stack **s);
Item  pop(Stack **s);
void push(Stack **s, Item* val);
int precdOpr(char opr);
void operatorHandle(char opr,Stack**head);
double evaluatePostfix(char* postfix);
double infixToPostfix(char* infix);
#endif // INTERPRETER_STACKS_H
