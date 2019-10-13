#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t = 0;
	cin>>t;
	while(t--)
	{
		int n=0,i=0,count=0;
		cin>>n;
		int a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		for(i=0;i<n;i++)
		{
            int cur_min = INT_MAX;
            if(i == 0)
            {
                count++;
                cur_min = a[i];
            }
			else if(i<5 && i>0)
            {
                cur_min = *min_element(&a[0],&a[i]);
            }
            else
            {
                cur_min = *min_element(&a[i-5],&a[i]);
            }
            if(a[i]<cur_min)
            {
                count++;
            }
		}
        cout<<count<<endl;
	}
	return 0;
}