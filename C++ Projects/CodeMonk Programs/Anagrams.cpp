#include<iostream>
#include<string.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        char string1[1000], string2[1000];
        cin>>string1>>string2;
        int count=0;
        int len1=strlen(string1);
        int len2=strlen(string2);
        for(int i=0;i<len1;i++)
        {
            for(int j=0;j<len2;j++)
            {
                if(string1[i]==string2[j])
                {
                    string1[i]='\0';
                    string2[j]='\0';
                }
            }
        }
        for(int i=0;i<len1;i++)
        {
            if(string1[i]!='\0')
            {
                count++;
            }
        }
        for(int i=0;i<len2;i++)
        {
            if(string2[i]!='\0')
            {
                count++;
            }
        }
        cout<<count<<endl;
    }
}