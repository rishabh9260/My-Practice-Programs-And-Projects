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
            int sum = 0;
            for(int i=0;i<(n+1)/2;i++)
                sum += a[i];
            if(sum>max)
                max = sum;
            for(int i=1; i<(n/2)+1;++i)
            {
                sum = sum + a[i+(n+1)/2-1] - a[i-1];
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