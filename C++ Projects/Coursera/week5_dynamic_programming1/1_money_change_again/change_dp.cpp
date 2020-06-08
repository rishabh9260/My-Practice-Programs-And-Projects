#include<bits/stdc++.h>
using namespace std;

int get_change(int m) {
  //write your code here
  vector<int> minNum(m+1, 0);
  vector<int> coins = {1, 3, 4};
  minNum[0] = 0;
  for(int i=1; i<m+1; i++)
  {
    minNum[i] = INT_MAX;
    for(auto j:coins)
    {
      if(i>=j)
      {
        int numCoins = minNum[i-j] + 1;
        if(minNum[i]>numCoins)
          minNum[i] = numCoins;
      }
    }
  }
  return minNum[m];
}

int main() {
  int m;
  cin >> m;
  cout << get_change(m) << '\n';
}
