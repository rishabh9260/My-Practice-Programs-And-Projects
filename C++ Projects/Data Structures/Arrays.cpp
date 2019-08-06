#include<iostream>
#include<vector>
#include<stdlib.h>
#include<conio.h>
using namespace std;

void arrayInsert(vector<int>&, int a);
int arraySearch(vector<int>, int a);
void arrayDelete(vector<int>&, int a);
void displayArray(vector<int>);

int main()
{
    int ch = 0;
    int a;
    vector<int> arr;
    do
    {   
        do
        {
            cout<<endl;
            system("pause");
            system("cls");
            cout<<"\nArrays Program!!!\n\n";
            cout<<"1. Insert in the array\n";
            cout<<"2. Search a element in the array\n";
            cout<<"3. Delete from the array\n";
            cout<<"4. Display elements of the array\n";
            cout<<"5. Exit\n";
            cout<<"\nEnter your choice:";
            cin>>ch;
            if(ch < 1 || ch > 5)
                cout<<"Invalid Choice!! Try again\n\n";
        }while(ch < 1 || ch > 5);

        switch(ch)
        {
            case 1: cout<<"Enter the element in the array:\n";
                    cin>>a;
                    arrayInsert(arr,a);
                    break;
            case 2: cout<<"Enter the element to be searched:";
                    cin>>a;
                    int flag; 
                    flag = arraySearch(arr,a);
                    if(flag == -1)
                        cout<<"\nElement Not Found!";
                    else
                    {
                        cout<<"\nElement found at index "<<flag<<endl;
                    }
                    break;
            case 3: cout<<"\nEnter element to be deleted:";
                    cin>>a;
                    arrayDelete(arr, a);
                    break;
            case 4: displayArray(arr);
                    break;
            case 5: cout<<"Exiting Program!!!";
                    exit(0);
        }
    }while(ch >= 1 || ch <= 5);

    return 0;
}

void arrayInsert(vector<int> &arr, int a)
{
    arr.push_back(a);
}

int arraySearch(vector<int> arr, int a)
{
    for(int i = 0; i<arr.size(); i++)
    {
        if(arr.at(i) == a)
        {
            return i;
        }
        else
        {
            continue;
        }
        
    }
    return -1;
}

void arrayDelete(vector<int> &arr, int a)
{
    int flag = 0;
    for(vector<int>::iterator i = arr.begin(); i<arr.end(); ++i)
    {
        if(*i == a)
        {
            arr.erase(i);
            flag = 1;
            break;
        }        
    }
    if(flag == 0)
        cout<<"\nElement does not exist in the array!!";
}

void displayArray(vector<int> arr)
{
    if(arr.empty())
    {
        cout<<"\nArray is empty!";
    }
    else
    {    
        cout<<"\nDisplaying the array!\n";
        for(int i = 0; i<arr.size(); i++)
        {
            cout<<arr[i]<<"\t";
        }
    }
}