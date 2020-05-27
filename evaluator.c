#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<ctype.h>
void err(int x,char * buff)
{
    switch(x)
    {
    case 4:
        printf("problem in string: %s\n",buff);
        puts("unbalance parentheses");
        exit(1);
    case 5:
        printf("problem in string: %s\n",buff);
        puts("operator at extremities");
        exit(1);
    case 6:
         printf("problem in string: %s\n",buff);
        puts("operator overload");
        exit(1);
    case 7:
         printf("problem in string: %s\n",buff);
        puts("void parentheses");
        exit(1);
    case 8:
       printf("problem in string: %s\n",buff);
        puts("undefined character");
        exit(1);
    case 9:
        puts("right-handside not found");
        exit(1);
    case 10:
        printf("problem in string: %s\n",buff);
        puts("radix point error");
        exit(1);
    }
}
void checker_bracket(char* buff)
{
    int count=0;
    for(int i=0; i<strlen(buff); i++)
    {
        switch(buff[i])
        {
        case '(':
            count++;
            break;
        case ')':
            count--;
            if(count<0)
                err(4,buff);
            break;
        }
    }
    if(count!=0)
        err(4,buff);
}

double rightside_evaluation(char * str)
{
    int len=strlen(str);
    if(!len)
        err(9,str);
    char key[]= "+-*/^()";
    char operators[]="+*/^";
    char buff[2*len];
    memset(buff,0,2*len);
    int radix_flag=1;
    char token=str[0];
    if(strchr(operators,token)!=NULL||token=='.')
        err(5,str);
    strncat(buff,&token, 1);
    for(int i=1; i<len; i++)
    {
        token =str[i];
        if(token=='-')
        {
            if(isalpha(str[i-1])||isdigit(str[i-1])||str[i-1]==')')
            {
                radix_flag=1;
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
                    err(6,str);
            }
            if(strchr(operators,str[i+1])!=NULL||str[i+1]=='\0')
                err(5,str);
        }
        else if(strchr(operators,token)!=NULL)
        {
            if(strchr(key,str[i-1])!=NULL||str[i-1]=='('||str[i-1]=='-')
                err(5,str);
            else
            {
                radix_flag=1;
                strcat(buff," ");
                strncat(buff,&token, 1);
                strcat(buff," ");
            }
            if(str[i+1]=='\0'||str[i+1]==')')
                err(5,str);
        }
        else if (token=='(')
        {
            radix_flag=1;
            if(str[i+1]==')'||str[i-1]==')')
                err(7,str);
            else
            {
                strncat(buff,&token, 1);
                strcat(buff," ");
            }
        }
        else if (token==')')
        {
            radix_flag=1;
            strcat(buff," ");
            strncat(buff,&token, 1);
        }
        else if(isdigit(token))
            strncat(buff,&token, 1);
        else if(token=='.')
        {
            if(radix_flag&&isdigit(str[i+1])&&isdigit(str[i-1]))
                strncat(buff,&token,1);
            else
                err(10,str);
            radix_flag--;
        }
        else if(token=='_'||isalpha(token))
            strncat(buff,&token, 1);
        else
            err(8,str);
    }
    //return stack infix to postfix{str}
    printf("%s",buff);
}

