#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, count = 0;
        string s;
        cin>>s;
        n = s.size();
        for(int i = n-1;i>=0;i--)
        {
            if(s[i]=='1')
            {
                cout<<i<<endl;
                count++;
                break;
            }
        }

        if(count == 0)
        {
            cout<<-1<<endl;
        }
    }
}