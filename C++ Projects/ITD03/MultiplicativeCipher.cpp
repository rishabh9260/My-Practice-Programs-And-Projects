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
        s[i] = (((int)s[i] - 'a') * key)%26 + 'a';
    }
    cout<<"The encrypted text is: "<<s<<endl;
    int m_inv = 0;
    for(int i = 0; i < 26; i++) 
    { 
        int flag = (key * i) % 26; 
        if (flag == 1) 
        {  
            m_inv = i;
            break;
        } 
    } 
    for(int i=0;i<s.length();i++)
    {
        s[i] = (((int)s[i] - 'a')*m_inv)%26 + 'a';
    }
    cout<<"The decrypted text is: "<<s<<endl;
    return 0;
}