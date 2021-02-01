#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cout<<"Enter the plaintext: ";
    cin>>s;
    int key1, key2;
    cout<<"Enter the key 1: ";
    cin>>key1;
    cout<<"Enter the key 2: ";
    cin>>key2;
    for(int i=0;i<s.length();i++)
    {
        s[i] = ((((int)s[i] - 'a') * key1) + key2)%26 + 'a';
    }
    cout<<"The encrypted text is: "<<s<<endl;
    int m_inv = 1;
    for(int i = 0; i < 26; i++) 
    { 
        int flag = (key1 * i) % 26; 
        if (flag == 1) 
        {  
            m_inv = i;
            break;
        } 
    } 
    for(int i=0;i<s.length();i++)
    {
        if((int)s[i] - 'a' - key2 < 0)
            s[i] += 26;
        s[i] = (((int)s[i] - 'a' - key2)*m_inv)%26 + 'a';
    }
    cout<<"The decrypted text is: "<<s<<endl;
    return 0;
}