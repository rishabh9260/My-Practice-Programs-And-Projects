#include<iostream>
#include<string>
#include<string.h>

using namespace std;

void push(char stack[],char a)
{
    stack[strlen(stack)]=a;
}

char pop(char stack[])
{
    char a=stack[strlen(stack)-1];
    stack[strlen(stack)-1]='\0';
    return a;
}

int precedence(char a)
{
    if(a=='^' || a=='%') return 3;
    else if(a=='*' || a=='/') return 2;
    else if(a=='+' || a=='-') return 1;
    else return -1;
}

int main()
{
    string exp;

    cout<<"\nEnter the Expression(no spaces) : ";
    cin>>exp;

    string post;
    char stack[20];

    push(stack,'(');

    for(int i=0;i<exp.size();i++)
    {
        if(exp[i]>='0' && exp[i]<='9') 
        {
            post += exp[i];
        }
        else if(exp[i]=='(') 
        {
            push(stack,exp[i]);
        }
        else if(exp[i]==')')
        {
            while(stack[strlen(stack)-1]!='(')
            {
                char a = pop(stack);
                post += a;
            }
            pop(stack);
        }
        else
        {
            while(precedence(exp[i])<=precedence(stack[strlen(stack)-1]))
        
    
        
    
            {
                char a = pop(stack);
                post+=a;
            }
            push(stack,exp[i]);
        }
    }
    while(stack[strlen(stack)-1]!='(')
    {
        char a = pop(stack);
        post += a;
    }
    cout<<post;

    return 0;
}