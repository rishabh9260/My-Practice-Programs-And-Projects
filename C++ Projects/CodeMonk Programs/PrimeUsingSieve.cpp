#include<iostream>
#include<cstring>
using namespace std;

void prime(int);

int main()
{
    int n;
    cin>>n;
    prime(n);
    
    return 0;
}

void prime(int n)
{
    bool prime[n+1];
    memset(prime, true, sizeof(prime));
    
    for(int i=2; i*i<=n; i++)
    {
        if(prime[i]==true)
        {
            for(int j=2;j<=n/i;j++)
            {
                prime[i*j] = false;
            }
        }
    }
    for(int i=2;i<=n;i++)
    {
        if(prime[i]==true)
        {
            cout<<i<<" ";
        }
    }
}