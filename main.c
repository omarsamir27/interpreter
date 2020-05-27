#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<ctype.h>
void err(int x)
{
    switch(x){
        case 4:
            puts("unbalance parentheses");
        exit(1);
        break;
        case 5:
            puts("operator at extremities");
        exit(1);
        break;
        case 6:
            puts("operator overload");
        exit(1);
        break;
        case 7:
            puts("void parentheses");
        exit(1);
        break;
        case 8:
            puts("undefined character");
        exit(1);
        break;
        case 9:
            puts("right-handside not found");
        exit(1);
        break;
        case 10:
            puts("radix point error");
        exit(1);
        break;
}}
void checker_bracket(char* buff)
{ int count=0;
    for(int i=0;i<strlen(buff);i++)
    {
        switch(buff[i])
        {
        case '(':
            count++;
            break;
        case ')':
            count--;
            if(count<0)
                {err(4);}
            break;
        }

    } if(count!=0)
           {
              err(4);
           }
}
void rightside_evaluation(char * str)
{
    double num;
    int len=strlen(str);
    if(!len)
        err(9);
    char key[]= "+-*/^()";
    char operators[]="+*/^";
    char buff[2*len];
    char temp[30];
    int radix_flag=1;
    memset(buff,0,2*len);
    char token=str[0];
    if(strchr(operators,token)!=NULL||token=='.')
       err(5);
    strncat(buff,&token, 1);
    for(int i=1; i<len; i++)
    {
        token =str[i];
        if(token=='-')
        {
            if(isalpha(str[i-1])||isdigit(str[i-1])||str[i-1]==')')
            {   radix_flag=1;
                strcat(buff," ");
                strncat(buff,&token, 1);
                strcat(buff," ");
            }
            else if(str[i-1]=='-'||strchr(operators,str[i-1])!=NULL||str[i-1]=='(')
            {
                if(isalpha(str[i+1])||str[i+1]=='(')
                  strcat(buff,"-1 * ");
                  else if(isdigit(str[i+1]))
                    strncat(buff,&token, 1);
                else
                    {err(6);}
                }
            if(strchr(operators,str[i+1])!=NULL||str[i+1]=='\0')
              {err(5);}
            }
        else if(strchr(operators,token)!=NULL)
        {
            if(strchr(key,str[i-1])!=NULL||str[i-1]=='('||str[i-1]=='-')err(5);
                else
                {     radix_flag=1;
                    strcat(buff," ");
                    strncat(buff,&token, 1);
                    strcat(buff," ");
                }
            if(str[i+1]=='\0'||str[i+1]==')')
             {err(5);}
            }
        else if (token=='(')
        {   radix_flag=1;
            if(str[i+1]==')'||str[i-1]==')')
                {err(7);}
            else
            {strncat(buff,&token, 1);
            strcat(buff," ");}
        }
        else if (token==')')
        {   radix_flag=1;
            strcat(buff," ");
            strncat(buff,&token, 1);
        }
        else if(isdigit(token))
            strncat(buff,&token, 1);
        else if(token=='.')
            {
                if(radix_flag&&isdigit(str[i+1])&&isdigit(str[i-1]))  strncat(buff,&token,1);
                else err(10);
                 radix_flag--;
            }
        else if(token=='_'||isalpha(token))
         strncat(buff,&token, 1);
        else
            err(8);
    }
   checker_bracket(buff);

    printf("%s",buff);}
void main()
    {
        char str[] = "0.0";
        rightside_evaluation(str);
    }
