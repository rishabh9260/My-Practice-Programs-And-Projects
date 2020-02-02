#include<fstream>
#include<iostream>
using namespace std;

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int a,b;
    fin>>a>>b;
    fout<<a+b;
    return 0;
}