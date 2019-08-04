#include<iostream>
#include<vector>
using namespace std;

void arrayInsert(vector<char>, char a);
char arraySearch(vector<char>, char a);
void arrayDelete(vector<char>, char a);
void arrayInsert(vector<int>, int a);
int arraySearch(vector<int>, int a);
void arrayDelete(vector<int>, int a);

int main()
{
    int ch = 0;
    char a;
    int a;
    vector<int> arr;
    vector<char> arr;
    do
    {   
        do
        {
            cout<<"Arrays Program!!!\n\n";
            cout<<"1. Insert in the array\n";
            cout<<"2. Search a element in the array\n";
            cout<<"3. Delete from the array\n";
            cout<<"4. Exit\n";
            cout<<"\nEnter your choice:";
            cin>>ch;
            if(ch < 1 || ch > 4)
                cout<<"Invalid Choice!! Try again";
        }while(ch < 1 || ch > 4);

        switch(ch)
        {
            case 1: cout<<"Enter the element in the array:\n";
                    cin>>a;
                    arrayInsert(arr,a);
                    break;
            case 2: cout<<"Enter the element to be searched:";
                    cin>>a;
                    int flag = arraySearch(arr,a);
                    if(flag == NULL || flag == -1)
                        cout<<"\nElement Not Found!";
                    else
                    {
                        cout<<"\nElement found at index "<<flag;
                    }
                    break;
            case 3: cout<<"\nEnter element to be deleted:";
                    cin>>a;
                    arrayDelete(arr,a);
                    break;
            case 4: cout<<"Exiting Program!!!";
                    exit(0);
        }
    }while(ch >= 1 || ch <= 4);

    return 0;
}

void arrayInsert(vector<char> arr, char a)
{
    arr.push_back(a);
}

void arrayInsert(vector<int> arr, int a)
{
    arr.push_back(a);
}

char arraySearch(vector<char> arr, char a)
{
    for(int i = 0; i<arr.size(); ++i)
    {
        if(arr[i] == a)
        {
            return i;
        }
        else
        {
            return NULL;
        }
        
    }
}

int arraySearch(vector<int> arr, int a)
{
    for(int i = 0; i<arr.size(); ++i)
    {
        if(arr[i] == a)
        {
            return i;
        }
        else
        {
            return -1;
        }
        
    }
}

void arrayDelete(vector<char> arr, char a)
{
    for(vector<char>::iterator i = arr.begin(); i<arr.end(); ++i)
    {
        if(*i == a)
        {
            arr.erase(i);
        }
        else
        {
            cout<<"\nElement does not exist in the array!";
        }
        
    }
}

void arrayDelete(vector<int> arr, int a)
{
    for(vector<int>::iterator i = arr.begin(); i<arr.end(); ++i)
    {
        if(*i == a)
        {
            arr.erase(i);
        }
        else
        {
            cout<<"\nElement does not exist in the array!";
        }
        
    }
}