#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n],b[2*n],c[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        b[i]=i+1;
        b[n+i]=i+1;
    }
    for(int i=0;i<n;i++)
        {
            for(int j=i,k=0;j<n && k<n;j++,k++)
            {
                c[k] = a[k] + b[j];
            }
            cout<<*max_element(&c[0], &c[n])<<" ";
        }
    return 0;
}