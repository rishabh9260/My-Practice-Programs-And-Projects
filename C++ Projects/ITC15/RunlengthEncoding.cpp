#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cout<<"Enter the string for encoding: ";
    cin>>s;
    string res = "";
    for(int i=0;i<s.size()-1;i++)
    {
        res += s[i];
        int count = 1;
        while(s[i+1]==s[i])
        {
            count++;
            i++;
        }
        if(count!=1)
            res += count + '0';
    }
    cout<<endl<<"The string after encoding is: "<<res;
    string decode;
    for(int i=0;i<res.size();i++)
    {
        decode += res[i];
        if(i != res.size()-1)
        {
            if(isdigit(res[i+1]))
            {
                int x = res[i+1] - '0';
                while(--x)
                {
                    decode += res[i];
                }
                i++;
            }
        }      
    }
    cout<<"\nThe string after decoding is: "<<decode;
    return 0;
}