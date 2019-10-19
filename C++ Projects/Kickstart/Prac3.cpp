#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t=0;
    cin>>t;
    int count=t;
    while(t--)
    {
        int n=0,k=0,x=0,y=0,c=0,d=0,e1=0,e2=0,f=0;
        cin>>n>>k>>x>>y>>c>>d>>e1>>e2>>f;
        int a[n];
        for(int i=0;i<n;i++)
        {
            a[i] = (x+y)%f;
            int x1;
            x1 = (c*x + d*y + e1)%f;
            y = (d*x + c*y + e2)%f;
            x=x1;
        }

        long long int sum = 0;
        for(int i=0;i<n;i++)
        {
            sum += (n-i)*a[i]*k;
            for(int j=0;j<i;j++)
            {
                sum += (n-i)*a[i]*((j+2)*((pow((j+2),k)-1)/(j+1)));
            }
        }
        sum %= 1000000007;
        cout<<"Case #"<<count-t<<": "<<sum<<endl<<flush;
    }
    return 0;
}