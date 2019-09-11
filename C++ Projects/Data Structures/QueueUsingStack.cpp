#include<bits/stdc++.h>
using namespace std;

void insert(stack<int> &p, stack<int> &s)
{
    int x;
    cout<<"\nEnter the element: ";
    cin>>x;
    p.push(x);
}

void deleteElement(stack<int> &p, stack<int> &s)
{
    if(p.empty())
    {
        cout<<"Underflow!!";
    }
    else
    {
        while(!p.empty())
        {
            int x = p.top();
            s.push(x);
            p.pop();
        }
        cout<<"The element that is being deleted: "<<s.top();
        cout<<endl;
        s.pop();
        while(!s.empty())
        {
            int x = s.top();
            p.push(x);
            s.pop();
        }
    }
}

void display(stack<int> &p, stack<int> &s)
{
    if(p.empty())
    {
        cout<<"Underflow!!";
    }
    else
    {
        while(!p.empty())
        {
            int x = p.top();
            s.push(x);
            p.pop();
        }
        cout<<endl;
        while(!s.empty())
        {
            int x = s.top();
            cout<<x<<"  ";
            p.push(x);
            s.pop();
        }
        cout<<endl<<endl;
    }
}

int main()
{
    stack<int> p,s;
    int ch;
    while(true)
    {
        cout<<"1. Input into queue.\n";
        cout<<"2. Delete from queue.\n";
        cout<<"3. Display the queue.\n";
        cout<<"4. Exit.\n";
        cout<<"Enter Choice: ";
        cin>>ch;
        if(ch == 1)
            insert(p,s);
        else if(ch == 2)
            deleteElement(p,s);
        else if(ch == 3)
            display(p,s);
        else if(ch == 4)
            exit(0);
        else
            cout<<"Invalid Choice!!";
        
    }
    return 0;
}