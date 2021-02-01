#include <bits/stdc++.h>
using namespace std;

char palindrome(string str)           // str is the given input string.
{

    // WRITE YOUR CODE HERE
    int n = str.size();
    n = n/2;
    int arr[26] = {0};
    for(int i=n;i<str.size();i++)
    {
        arr[tolower(str[i]) - 'a']++;
    }
    int count = 0;
    bool flag = false;
    if((str.size()-n)%2 == 0)
        flag = true;
    for(int i=0;i<26;i++)
    {
        if(arr[i]%2 != 0)
        {
            if(arr[i]%2 == 1 && flag)
                return 'N';
            else if(arr[i]%2 == 1 && !flag)
                count++;
        }
    }
    if(count > 1)
        return 'N';
    return 'Y';
}

int main() {

    int N;
    cin >> N;
    string a[N];
    for(int i=0; i<N; i++)
        cin >> a[i];
    for(int i=0; i<N; i++)
        cout<<palindrome(a[i])<<endl;
}
