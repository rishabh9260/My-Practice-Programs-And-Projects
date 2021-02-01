#include <bits/stdc++.h>

using namespace std;

int main()
{
	// Write your code here
	int n,m;
	cin>>n>>m;
	vector<set<int> > arr;
	set<int> st;
	int x,y;
	cin>>x>>y;
	st.insert(x);
	st.insert(y);
	arr.push_back(st);
	for(int i=1;i<m;i++)
	{
	    int a,b, flag = 0;
	    cin>>a>>b;
	    int sz = arr.size();
	    for(int j=0;j<sz;j++)
	    {
	        if(arr[j].find(a) != arr[j].end() || arr[j].find(b) != arr[j].end())
	           {
	               arr[j].insert(a);
	               arr[j].insert(b);
	               flag = 1;
	               break;
	           }
	    }
	    if(flag==0) 
	    {
	        set<int> st1;
	        st1.insert(a);
	        st1.insert(b);
	        arr.push_back(st1);
	    }
	}
	vector<long long int> scores;
	for(int i=0;i<n;i++)
	{
	    long long int a;
	    cin>>a;
	    scores.push_back(a);
	}
	vector<int> res(arr.size());
	int k = arr.size();
	for(int i=0;i<k;i++)
	{
	    int sum = 0;
	    for(set<int>::iterator j=arr[i].begin();j!=arr[i].end();j++)
	    {
	        sum += scores[*j-1];
	    }
	    res.push_back(sum);
	}
	cout<<*max_element(res.begin(), res.end());
	return 0;
}