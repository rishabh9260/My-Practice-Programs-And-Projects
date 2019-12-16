#include<iostream> 
#include<stdlib.h> 
  
using namespace std; 
  
class twoStacks 
{ 
    int *arr; 
    int size; 
    int top1, top2; 
public: 
   twoStacks(int n) 
   { 
       size = n; 
       arr = new int[n]; 
       top1 = -1; 
       top2 = size; 
   } 
  
   void push1(int x) 
   { 
       if (top1 < top2 - 1) 
       { 
           top1++; 
           arr[top1] = x; 
       } 
       else
       { 
           cout << "Stack Overflow"; 
           return;
       } 
   } 
  
   void push2(int x) 
   { 
       if (top1 < top2 - 1) 
       { 
           top2--; 
           arr[top2] = x; 
       } 
       else
       { 
           cout << "Stack Overflow"; 
           return; 
       } 
   } 
  
   int pop1() 
   { 
       if (top1 >= 0 ) 
       { 
          int x = arr[top1]; 
          top1--; 
          return x; 
       } 
       else
       { 
           cout << "Stack UnderFlow"; 
           return INT_MIN;
       } 
   } 
  
   int pop2() 
   { 
       if (top2 < size) 
       { 
          int x = arr[top2]; 
          top2++; 
          return x; 
       } 
       else
       { 
           cout << "Stack UnderFlow"; 
           return INT_MIN; 
       } 
   } 
}; 
  
int main() 
{ 
    int n;
    cout<<endl<<"Enter the size of array : ";
    cin>>n;

    twoStacks ts(n);

    int ch;
    do
    {
        cout<<endl<<"Enter 1 to push in 1st stack";
        cout<<endl<<"Enter 2 to push in 2nd stack";
        cout<<endl<<"Enter 3 to pop from 1st stack";
        cout<<endl<<"Enter 4 to pop from 2nd stack";
        cout<<endl<<"Enter 0 to exit";
        cout<<endl<<"Enter the choice: ";
        cin>>ch;
        int x;
        switch(ch)
        {
            case 0: exit(0);

            case 1: cout<<"Enter the element you want to push: ";
                    cin>>x;
                    ts.push1(x);
                    break;
            case 2: cout<<"Enter the element you want to push: ";
                    cin>>x;
                    ts.push2(x);
                    break;
            case 3: x=ts.pop1();
                    if(x!= INT_MIN) cout<<"The popped element is: "<<x;
                    break;
            case 4: x=ts.pop2();
                    if(x!= INT_MIN) cout<<"The popped element is: "<<x;
                    break;
            default: cout<<"Wrong choice...."<<endl;
                     break;
        }
    }while(ch);
} 