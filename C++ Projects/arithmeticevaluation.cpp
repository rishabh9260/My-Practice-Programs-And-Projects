#include<bits/stdc++.h>
#include<math.h>

using namespace std;

int precedence(char a)      //Function to return the precedence level of the operator
{
    if(a=='%') return 3;
    else if(a=='*' || a=='/') return 2;
    else if(a=='+' || a=='-') return 1;
    else return -1;
}

string infixToPostfix(string exp)
{
    string postfix;
    string stack;
    stack += 'N';

    for(int i=0;i<exp.size();i++)
    {
        if(exp[i]>='0' && exp[i]<='9') 
        {
            postfix += exp[i];
        }
        else if(exp[i]=='(') 
        {
            stack += exp[i];
        }
        else if(exp[i]==')')
        {
            while(stack[stack.size()-1]!='(')
            {
                char a = stack[stack.size()-1]; 
                stack.pop_back();
                postfix += a;
            }
            stack.pop_back();
        }        
        else
        {
            while(precedence(exp[i])<=precedence(stack[stack.size()-1]))
            {
                char a = stack[stack.size()-1];
                stack.pop_back();
                postfix+=a;
            }
            stack += exp[i];
        }
    }
    while(stack[stack.size()-1]!='N')
    {
        char a = stack[stack.size()-1];
        stack.pop_back();
        postfix += a;
    }
    return postfix;
}

int evaluate(string postfix)
{
    vector<int> stack;
    int a,b,x;
    for(int i=0;i<postfix.size();i++)
    {
        if(postfix[i]>='0' && postfix[i]<='9')
        {
            stack.push_back(postfix[i]-'0');
        }
        else
        {
            a = stack[stack.size()-1];
            stack.pop_back();
            b = stack[stack.size()-1];
            stack.pop_back();
            switch(postfix[i])
            {
                case '+': x = b+a;
                          break;
                case '-': x = b-a;
                          break;
                case '*': x = b*a;
                          break;
                case '/': x = b/a;
                          break;
                case '%': x = b%a;
                          break;
            }
            stack.push_back(x);
        }
    }
    return stack[0];
}

int main()
{
    string exp,postfix;

    cout<<"\nEnter the Expression(no spaces and numbers only) : ";
    cin>>exp;

    postfix = infixToPostfix(exp);    
    cout<<endl<<"The postfix expression : "<<postfix<<endl;

    int x=evaluate(postfix);
    cout<<endl<<"The Answer is : "<<x<<endl;
    return 0;
}