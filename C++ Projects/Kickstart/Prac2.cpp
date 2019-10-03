#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t = 0;
    cin>>t;
    int k = 1;
    while(k<=t)
    {
        int n = 0;
        cin>>n;
        char b[n];
        int a[n];
        for(int i=0;i<n;i++)
        {
            cin>>b[i];
            a[i] = (int)b[i] - 48;
        }
        fflush(stdin);
        fflush(stdout);
        if(n==2)
            cout<<"Case #"<<k<<": "<<(a[0]>a[1]?a[0]:a[1])<<endl<<flush;
        else
        {
            int max = 0;
            for(int i=0; i<(n%2==0?n/2:(n/2)+1);++i)
            {
                int sum = 0;
                for(int j=i,k=0;k<(n%2==0?n/2:(n/2)+1);j++,k++)
                {
                    sum = sum + a[j];
                }
                if(sum>max)
                {
                    max = sum;
                }
            }
            cout<<"Case #"<<k<<": "<<max<<endl<<flush;
        }
        k++;
    }
}