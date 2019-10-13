#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k,x,y,c,d,e1,e2,f;
        cin>>n>>k>>x>>y>>d>>e1>>e2>>f;
        int a[n];
        for(int i=1;i<n;i++)
        {
            a[i] = (x+y)%f;
            x = c*x + d*y + e1;
            y = d*x + c*y + e2;
        }
        
    }
}