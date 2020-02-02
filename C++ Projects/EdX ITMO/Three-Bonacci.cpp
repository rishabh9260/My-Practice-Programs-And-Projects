#include<fstream>
#include<iostream>
using namespace std;

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int a,b,c,n,t;
    fin>>a>>b>>c>>n;
    if(n==0)
        t=a;
    else if(n==1)
        t=b;
    else if(n==2)
        t=c;
    else
    {
        for(int i=3;i<=n;i++)
        {
            t=c+b-a;
            a=b;
            b=c;
            c=t;
        }
    }
    fout<<t<<endl;
    return 0;
}