#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    int c=1;
    while(c<=t)
    {
        long long int n=0,m=0,sum=0,flag=0;
        long long int maxk=INT_MIN;
        cin>>n>>m;
        long long int a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        long long int counter=0;
        if(*max_element(&a[0],&a[n])<m)
        {
            counter = m;
        }
        else
        {
            counter = *max_element(&a[0],&a[n]);
        }
        
        long long int k=0;
        while(k<=2*counter)
        {
            sum = 0;
            for(int i=0;i<n;i++)
            {
                sum = sum + (a[i]^k);
            }
            if(sum<=m && k>=maxk)
            {
                maxk=k;
            }
            k++;
        }
        if(maxk==INT_MIN)
        {
            maxk = -1;
        }
        cout<<"Case #"<<c<<": "<<maxk<<endl<<flush;
        c++;
    }
    return 0;
}