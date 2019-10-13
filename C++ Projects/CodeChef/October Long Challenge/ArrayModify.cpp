#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,a,b;
        long long int k;
        cin>>n>>k;
        int final[n],copy[n],xor_arr[n/2];
        for(int i=0;i<n;i++)
        {
            cin>>final[i];
            copy[i] = final[i];
        }
        for(int i=0;i<n/2;i++)
        {
            a=final[i%n];
            b=final[n-(i%n)-1];
            xor_arr[i%n]=a^b;
        }
        if(k>=n)
        {
            if(((k/n)-1)%3 == 0)
            {
                for(int i=0;i<n/2;i++)
                {
                    final[i%n] = xor_arr[i%n];
                    final[n-(i%n)-1] = copy[i%n];
                }
            }
            else if(((k/n)-2)%3 == 0)
            {
                for(int i=0;i<n/2;i++)
                {
                    final[n-(i%n)-1] = xor_arr[i%n];
                    final[i%n] = copy[n-(i%n)-1];
                }
            }
            if(n%2 == 1)
            {
               final[n/2] = 0; 
            }
        }
        for(int i=0;i<k%n;i++)
        {
            a=final[i%n];
            b=final[n-(i%n)-1];
            final[i%n]=a^b;
        }
        for(int i=0;i<n;i++)
        {
            cout<<final[i]<<" ";
        }
    }
}