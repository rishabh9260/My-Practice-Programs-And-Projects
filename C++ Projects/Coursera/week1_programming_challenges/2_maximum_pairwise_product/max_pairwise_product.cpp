#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    int n;
    cin>>n;
    vector<int> numbers(n);
    for(int i=0;i<n;i++)
    {
        cin>>numbers[i];
    }

    ll result = *max_element(numbers.begin(),numbers.end());
    int max1 = max_element(numbers.begin(),numbers.end()) - numbers.begin();
    int max2 = 0;

    for(int i=0;i<numbers.size();i++)
    {
        if(i!=max1 && numbers[i]>max2)
            max2 = numbers[i];
    }

    result*= max2;

    cout<<result;

    return 0;
}