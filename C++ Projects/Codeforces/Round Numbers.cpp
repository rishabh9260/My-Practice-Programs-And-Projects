#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t = 0;
    cin>>t;
    while(t--)
    {
        string num;
        cin>>num;
        int zeroes = 0;
        int n = num.size();
        for(int i=0;i<n;i++)
        {
            if(num[i]=='0')
                zeroes++;
        }
        cout<<endl<<n - zeroes<<endl;
        for(int i=0;i<n;i++)
        {
            if(num[i]!='0')
                cout<<(int)(num[i] - '0') * pow(10,n-i-1)<<" ";
        }
    }
    return 0;
}