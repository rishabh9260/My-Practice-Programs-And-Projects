#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    string line;
    ifstream fin;
    fin.open("file.txt");
    if(fin.is_open())
    {
        cout<<"The contents of the file are:"<<endl;
        while(!fin.eof())
        {
            getline(fin, line);
            cout<<line<<endl;
        }
    }
    else
    {
        cout<<"File not opened correctly!"<<endl;
    }
    fin.close();
    ofstream fout;
    fout.open("file.txt", ios::app);
    if(fout.is_open())
    {
        cout<<"Enter the line to enter in the text file: ";
        getline(cin, line);
        fout<<line<<endl;
    }
    else
    {
        cout<<"File not opened correctly!";
    }
    fout.close();
    return 0;
}