#include<bits/stdc++.h>

using namespace std;

vector<int> optimal_sequence(int n) {
  vector<int> sequence;
  vector<int> arr(n+1);
  arr[0] = 0;
  for(int i=1; i<n+1; i++)
  {
    arr[i] = arr[i-1] + 1;
    if(i%2 == 0) arr[i] = min(1 + arr[i/2],arr[i]);
    if(i%3 == 0) arr[i] = min(1 + arr[i/3],arr[i]);
  }

  while (n >= 1) {
    sequence.push_back(n);
    if (arr[n-1] == arr[n] - 1)
    {
      n--;
    }
    else if (n % 2 == 0 && arr[n/2] == arr[n] - 1)
    {
      n /= 2;
    } 
    else if (n % 3 == 0 && arr[n/3] == arr[n] - 1)
    {
      n /= 3;
    }
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

int main() {
  int n;
  cin >> n;
  vector<int> sequence = optimal_sequence(n);
  cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    cout << sequence[i] << " ";
  }
}
