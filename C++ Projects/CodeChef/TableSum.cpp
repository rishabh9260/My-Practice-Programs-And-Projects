#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n],b[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    for(int i=0;i<n;i++)
        {
            int k=n;
            for(int j=i;k--;j++)
                {
                    if(j>n)
                        b[i] = a[i] + n-j-1;
                    else
                        b[i] = a[i] + j+1;
                }
            cout<<*max_element(&b[0], &b[n])<<" ";
        }
    return 0;
}