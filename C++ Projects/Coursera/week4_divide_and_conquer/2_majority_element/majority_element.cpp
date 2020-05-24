#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int get_majority_element(vector<int> &a, int left, int right) {
  if (left == right) return 0;
  if (left + 1 == right) return 1;
  //write your code here
  sort(a.begin(),a.end());
  int cur = 0;
  int count = 0;
  for(int i=left;i<right;i++)
  {
    if(a[i] != cur)
    {
      cur = a[i];
      count = 1;
    }
    else
    {
      count++;
    }
    if(count>(right/2))
      return 1;
  }
  return 0;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout <<get_majority_element(a, 0, a.size());
}
