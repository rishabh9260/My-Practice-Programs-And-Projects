#include <iostream>
#include<boost/multiprecision/cpp_int.hpp>

using namespace boost::multiprecision;
using namespace std;

cpp_int fact(cpp_int x)
{
    if(x == 1 || x == 0)
        return 1;
    else
        return x*fact(x-1);
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
	int n=0,x;
	cin>>n;
	while(n--)
	{
	    cin>>x;
	    cout<<fact(x)<<endl;
	}
	return 0;
}
