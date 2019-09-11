#include<bits/stdc++.h>

using namespace std;

int precedence(char a)        //Function to return the precedence level of the operator
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

string postfixToInfix(string postfix)
{
    stack<string> st;
    string x,y;
    for(int i=0;i<postfix.size();i++)
    {
        if(postfix[i]<='9' && postfix[i]>='0')
        {
            string a;
            a.push_back(postfix[i]);
            st.push(a);
        }
        else
        {
            y = st.top();
            st.pop();
            x = st.top();
            st.pop();

            string temp;

            //Conditions to add the brackets at the right places while converting back to infix

            if(x.size()==1)
                temp = x + postfix[i];
            else
            {
                int size_x = x.size() - 2;
                while(x[size_x] == ')' || (x[size_x] >= '0' && x[size_x] <= '9'))
                    size_x--;
                if(precedence(x[size_x]) >= precedence(postfix[i]))
                    temp = x + postfix[i];
                else
                    temp = '(' + x + ')' + postfix[i];
            }
            if(y.size()==1)
                temp += y;
            else
            {
                int size_y = 1;
                while(y[size_y] == '(' || (y[size_y] >= '0' && y[size_y] <= '9'))
                    size_y++;
                if(precedence(y[size_y]) >= precedence(postfix[i]))
                    temp += y;
                else
                    temp += '(' + y + ')';
            }
            st.push(temp);
        }
    }
    return st.top();
}

//Main Function

int main()
{
    string exp,postfix,output;

    cout<<"\nEnter the Expression(no spaces and use numbers only) : ";
    cin>>exp;
    postfix = infixToPostfix(exp); 
    cout<<"Postfix: "<<postfix;   
    if (postfix !="NULL") 
    {
        output = postfixToInfix(postfix);
        cout<<endl<<"After removing superfluous brackets: "<<output<<endl;
    }

    return 0;
}