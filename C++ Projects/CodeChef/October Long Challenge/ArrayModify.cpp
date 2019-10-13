#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k,a,b;
        cin>>n>>k;
        int arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        for(int i=0;i<k;i++)
        {
            a=arr[i%n];
            b=arr[n-(i%n)-1];
            arr[i%n]=a^b;
        }
        for(int i=0;i<n;i++)
        {
            cout<<arr[i]<<" ";
        }
    }
}