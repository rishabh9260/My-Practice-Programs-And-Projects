#include <bits/stdc++.h>

using namespace std;

int edit_distance(const string &str1, const string &str2) {
  //write your code here
  int m = str1.size()+1;
  int n = str2.size()+1;
  vector<vector<int>> dp(m, vector<int>(n));
  for(int i=0; i<m; i++)
  {
    dp[i][0] = i;
  }
  for(int i=0; i<n; i++)
  {
    dp[0][i] = i;
  }
  for(int i=1; i<m;i++)
  {
    for(int j=1; j<n; j++)
    {
      int ins = dp[i][j-1] + 1;
      int del = dp[i-1][j] + 1;
      int match = dp[i-1][j-1];
      int mismatch = dp[i-1][j-1] + 1;
      if(str1[i-1]==str2[j-1])
        dp[i][j] = min({ins, del, match});
      else
        dp[i][j] = min({ins, del, mismatch});      
    }
  }
  return dp[m-1][n-1];
}

int main() {
  string str1;
  string str2;
  cin >> str1 >> str2;
  cout << edit_distance(str1, str2) <<endl;
  return 0;
}
