#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        a[i] +=i+1;
    }
    cout<<*max_element(&a[0], &a[n])<<" ";
    int cur = 1;
    for(int i=0;i<n;i++)
        {
            if(n-cur > 0)
                a[n-i] -= (n-1); 

            cout<<*max_element(&a[0], &a[n])<<" ";
        }
    return 0;
}