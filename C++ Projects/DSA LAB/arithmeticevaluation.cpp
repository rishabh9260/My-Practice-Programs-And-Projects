#include<bits/stdc++.h>
#include<math.h>

using namespace std;

int prec(char a)
{
    if(a=='%') return 3;
    else if(a=='*' || a=='/') return 2;
    else if(a=='+' || a=='-') return 1;
    else return -1;
}

string intopost(string exp)
{
    string post;
    string stack;
    stack += 'N';

    for(int i=0;i<exp.size();i++)
    {
        if(exp[i]>='0' && exp[i]<='9') 
        {
            post += exp[i];
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
                post += a;
            }
            stack.pop_back();
        }
        else
        {
            while(prec(exp[i])<prec(stack[stack.size()-1]))
            {
                char a = stack[stack.size()-1];
                stack.pop_back();
                post+=a;
            }
            stack += exp[i];
        }
    }
    while(stack[stack.size()-1]!='N')
    {
        char a = stack[stack.size()-1];
        stack.pop_back();
        post += a;
    }
    return post;
}

int evaluate(string post)
{
    vector<int> stack;
    int a,b,x;
    for(int i=0;i<post.size();i++)
    {
        if(post[i]>='0' && post[i]<='9')
        {
            stack.push_back(post[i]-'0');
        }
        else
        {
            a = stack[stack.size()-1];
            stack.pop_back();
            b = stack[stack.size()-1];
            stack.pop_back();
            switch(post[i])
            {
                case '+': x = a+b;
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
    string exp,post;

    cout<<"\nEnter the Expression(no spaces) : ";
    cin>>exp;

    post = intopost(exp);    
    cout<<endl<<"The postfix expression : "<<post<<endl;

    int x=evaluate(post);
    cout<<endl<<"The Answer is : "<<x<<endl;
    return 0;
}