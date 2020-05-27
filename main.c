#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef union
{
    double dData;
    char  cData;
} Item;

typedef struct
{
    Item* data;
    struct node * next;

} node;
int character_match(char x,int y)//implement y  conditions
{
  const char symbols1[]="+-*/^(";
   const char symbols1[]="+-*/^)";
  int i=0;
  while(sybols[i]!='\0')
  {
      if(sybols[i]==x)
        return 1;
      i++;
  }
  return 0;
}

double rightside_evaluation(char * buff)
{ double num=0;

checker_bracket(buff);
return num;
}
int main()
{
  char buff[]="10.5+(z-2.5)/(x+y)";
  double num=rightside_evaluation(buff);
}
