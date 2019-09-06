#include<bits/stdc++.h>

using namespace std;

int precedence(char a)        //Function to return the precedence level of the operator
{
    if(a=='%') return 3;
    else if(a=='*' || a=='/') return 2;
    else if(a=='+' || a=='-') return 1;
    else return -1;
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
    string exp,output;

    cout<<"\nEnter the Postfix Expression(no spaces and use numbers only) : ";
    cin>>exp;  

    output = postfixToInfix(exp);
    cout<<endl<<"Resulting Infix: "<<output<<endl;

    return 0;
}