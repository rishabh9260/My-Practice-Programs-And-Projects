#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    int k=1;
    while(k<=t)
    {
        int n=0,m=0,q=0,count=0;
        cin>>n>>m>>q;
        int missing[m+1];
        int reader[q+1];
        int book[n+1]={0};
        for(int i=1;i<=m;i++)
        {
            cin>>missing[i];
            book[missing[i]] = -1;
        }
        for(int i=1;i<=q;i++)
        {
            cin>>reader[i];
        }
        if(m==n)
        {
            cout<<"Case #"<<k<<": 0"<<endl<<flush;
            k++;
            continue;
        }
        for(int i=1;i<=q;i++)
        {
            for(int j=reader[i];j<=n;j=j+reader[i])
            {
                if(book[j]!=-1)
                {
                    book[j] = 1;
                    count++;
                }
            }
        }
        cout<<"Case #"<<k<<": "<<count<<endl<<flush;
        k++;
    }
    return 0;
}