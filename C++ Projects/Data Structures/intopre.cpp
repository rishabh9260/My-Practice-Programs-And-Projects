#include<iostream>
#include<string>
#include<string.h>

using namespace std;

int precedence(char a)  //Function to return the precedence level of the operator
{
    if(a=='^' || a=='%') return 3;
    else if(a=='*' || a=='/') return 2;
    else if(a=='+' || a=='-') return 1;
    else return -1;
}

//Main Function

int main()
{
    string exp;

    cout<<"\nEnter the Expression(no spaces) : ";
    cin>>exp;

    string pre;
    string stack;

    for(int i=exp.size()-1;i>=0;i--)
    {
        if(isalpha(exp[i])) 
        {
            string a;
            a.push_back(exp[i]);
            pre.insert(0,a);
        }
        else if(exp[i]==')') 
        {
            stack += exp[i];
        }
        else if(exp[i]=='(')
        {
            while(stack[stack.size()-1]!=')')
            {
                string a;
                a += stack[stack.size()-1];
                stack.pop_back();
                pre.insert(0,a);
            }
            stack.pop_back();
        }
        else
        {
            while(precedence(exp[i])<=precedence(stack[stack.size()-1]))
            {
                string a;
                a += stack[stack.size()-1];
                stack.pop_back();
                pre.insert(0,a);
            }
            stack += exp[i];
        }
    }
    while(stack.size()!=0)
    {
        string a;
        a += stack[stack.size()-1];
        stack.pop_back();
        pre.insert(0,a);
    }
    cout<<pre;

    return 0;
}