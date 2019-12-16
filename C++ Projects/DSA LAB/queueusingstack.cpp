#include<bits/stdc++.h>

using namespace std;

int main()
{
    stack<int> prim,sec;

    int ch;
    do
    {
        cout<<endl<<endl<<"Enter 1 to push";
        cout<<endl<<"Enter 2 to pop";
        cout<<endl<<"Enter 3 to display";
        cout<<endl<<"Enter 0 to exit";
        cout<<endl<<"Enter your choice : ";
        cin>>ch;
        
        
        if(ch==0)
        {
            exit(0);
        }
        else if(ch==1)
        {
            cout<<"Enter the element you want to insert : ";
            int n;
            cin>>n;
            prim.push(n);
        }
        else if(ch==2)
        {
            if(prim.empty()) cout<<"\nUnderflow";
            else
            {
                while(!prim.empty())
                {
                    int p=prim.top();
                    prim.pop();
                    sec.push(p);
                }
                cout<<endl<<"The popped element is "<<sec.top();
                sec.pop();
                while(!sec.empty())
                {
                    int p=sec.top();
                    sec.pop();
                    prim.push(p);
                }
            }
        }
        else if(ch==3)
        {
            if(prim.empty()) cout<<"\nUnderflow";
            else
            {
                while(!prim.empty())
                {
                    int p=prim.top();
                    prim.pop();
                    sec.push(p);
                }
                while(!sec.empty())
                {
                    int p=sec.top();
                    sec.pop();
                    prim.push(p);
                    cout<<endl<<"\t"<<p;
                }
            }
        }
        else
        {
            cout<<endl<<"Wrong choice....";
        }
    }while(ch);
}