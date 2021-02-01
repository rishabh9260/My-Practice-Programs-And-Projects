#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cout<<"Enter the plaintext: ";
    cin>>s;
    int key;
    cout<<"Enter the key: ";
    cin>>key;
    for(int i=0;i<s.length();i++)
    {
        s[i] = ((int)s[i] - 'a' + key)%26 + 'a';
    }
    cout<<"The encrypted text is: "<<s<<endl;

    for(int i=0;i<s.length();i++)
    {
        if((int)s[i] - 'a' - key < 0)
            s[i] += 26;
        s[i] = ((int)s[i] - 'a' - key)%26 + 'a';
    }
    cout<<"The decrypted text is: "<<s<<endl;
    return 0;
}