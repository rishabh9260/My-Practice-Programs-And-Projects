#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t=0;
    cin>>t;
    while(t--)
    {
        int a,b;
        int n;
        cin>>a>>b;
        cin>>n;
        string s;
        int max = b;
        int min = a+1;
        int mid = (min + max)/2;
        for(int i=0;i<n;i++)
        {
            cout<<mid<<endl<<flush;
            cin>>s;
            if(s=="CORRECT")
            {
                break;
            }
            else if(s=="TOO_SMALL")
            {
                min = mid + 1;
            }
            else if(s=="TOO_BIG")
            {
                max = mid - 1;
            }
            else if(s=="WRONG_ANSWER")
            {
                exit(1);
            }
            mid = (max + min)/2;
        }
    }
}