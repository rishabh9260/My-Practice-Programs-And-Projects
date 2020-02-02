#include<fstream>
#include<iostream>
using namespace std;

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    long long int a,b;
    fin>>a>>b;
    fout<<a+(b*b);
    return 0;
}