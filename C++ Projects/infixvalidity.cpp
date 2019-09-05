#include<bits/stdc++.h>

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
        if(exp[i]>='0' && exp[i]<='9')      //Expression should only contain numbers
        {
            if(i!=(exp.size()-1))
            {
                if((exp[i+1]=='(')||(exp[i+1]>='0' && exp[i+1]<='9'))   //If a '(' or a number comes directly after a number
                {
                    cout<<"One operater is missing in your expression...."<<endl;
                    return "NULL";
                }
            }
            postfix += exp[i];
        }
        else if(exp[i]=='(')    //If ended with '('
        {
            if(i==(exp.size()-1))
            {
                cout<<"Incomplete Expression...."<<endl;
                return "NULL";
            }
            if((exp[i+1]=='+')||(exp[i+1]=='-')||(exp[i+1]=='*')||(exp[i+1]=='/')||(exp[i+1]=='%')) //Operator followed by a '('
            {
                cout<<"One operand is missing...."<<endl;
                return "NULL";
            }
            if(exp[i+1]==')')   //')' just after '('
            {
                cout<<"Sub-expression is missing..."<<endl;
                return "NULL";
            }
            stack += exp[i];
        }
        else if(exp[i]==')')        //Conditions regarding ')' brace
        {
            if(i==0)
            {
                cout<<"The closing brace ')' cannot be placed at first index..."<<endl;
                return "NULL";
            }
            if((exp[i-1]=='+')||(exp[i-1]=='-')||(exp[i-1]=='*')||(exp[i-1]=='/')||(exp[i-1]=='%'))
            {
                cout<<"Operand is missing...."<<endl;
                return "NULL";
            }
            if(i!=(exp.size()-1))
            {
                if((exp[i+1]>='0' && exp[i+1]<='9')||(exp[i+1]=='('))
                {
                    cout<<"Operater is missing....."<<endl;
                    return "NULL";
                }
            }
            while(stack[stack.size()-1]!='(' && stack[stack.size()-1]!='N')
            {
                char a = stack[stack.size()-1]; 
                stack.pop_back();
                postfix += a;
            }
            if(stack[stack.size()-1]=='N')
            {
                cout<<"One starting brace '(' missing...."<<endl;
                return "NULL";
            }
            stack.pop_back();
        }
        else if((exp[i]=='+')||(exp[i]=='-')||(exp[i]=='*')||(exp[i]=='/')||(exp[i]=='%'))  //Operator checks
        {
            if(i==0)
            {
                cout<<"No operater can be placed at first index... "<<endl;
                return "NULL";
            }
            if((exp[i+1]=='+')||(exp[i+1]=='-')||(exp[i+1]=='*')||(exp[i+1]=='/')||(exp[i+1]=='%'))
            {
                cout<<"An operand is missing...."<<endl;
                return "NULL";
            }
            while(precedence(exp[i])<=precedence(stack[stack.size()-1]))
            {
                char a = stack[stack.size()-1];
                stack.pop_back();
                postfix+=a;
            }
            stack += exp[i];
        }
        else 
        {
            cout<<endl<<"Your expression contains an invalid charecter..."<<endl;
            return "NULL";
        }
    }
    while(stack[stack.size()-1]!='N')
    {
        if(stack[stack.size()-1]=='(')
        {
            cout<<"One closing brace ')' missing...."<<endl;
            return "NULL";
        }
        char a = stack[stack.size()-1];
        stack.pop_back();
        postfix += a;
    }
    return postfix;
}

//Main Function

int main()
{
    string exp,postfix;

    cout<<"\nEnter the Expression(no spaces and numbers only) : ";
    cin>>exp;

    postfix = infixToPostfix(exp);    
    if (postfix !="NULL") 
        cout<<"The expression is correct! Here is the resulting postfix expression: "<<endl<<postfix;

    return 0;
}