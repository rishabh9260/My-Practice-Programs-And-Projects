//This program evaluates the given expression containing unary '-'.
//The underlying logic of the program is to replace unary '-' with '(0-1)*'
//And then solving it as usual from the postfix expression

#include<bits/stdc++.h>

using namespace std;

//The function to check the precedence of the encountered operater
int precedence(char a)
{
    if(a=='*' || a=='/') return 2;
    else if(a=='+' || a=='-') return 1;
    else return -1;
}

//The function to generate the postfix expression
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

//The function to finally evaluate
float evaluate(string postfix)
{
    vector<float> stack;
    float a,b,x;
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
                case '+': x = a+b;
                          break;
                case '-': x = b-a;
                          break;
                case '*': x = b*a;
                          break;
                case '/': x = b/a;
                          break;
            }
            stack.push_back(x);
        }
    }
    return stack[0];
}

//The function to replace unary '-' with '(0-1)*'
string unary(string exp)
{
    int s=exp.size();
    for(int i=0;i<s;i++,s=exp.size())
    {
        if(exp[i]=='-')
        {
            if(exp[i-1]=='+' || exp[i-1]=='-' || exp[i-1]=='*' || exp[i-1]=='/' || exp[i-1]=='(' || i==0)
            {
                exp.erase(i,1);
                string a="(0-1)*";
                exp.insert(i,a);
            }
        }
    }
    cout<<endl<<exp;
    return exp;
}

//Main Function

int main()
{
    string exp,postfix,un;

    cout<<"\nEnter the Expression(no spaces) : ";
    cin>>exp;

    un = unary(exp);

    postfix = infixToPostfix(un);    
    cout<<endl<<"The postfix expression : "<<postfix<<endl;

    float x=evaluate(postfix);
    cout<<endl<<"The Answer is : "<<x<<endl;
    return 0;
}