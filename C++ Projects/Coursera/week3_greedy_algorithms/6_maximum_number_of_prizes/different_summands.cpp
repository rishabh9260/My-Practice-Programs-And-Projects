#include <iostream>
#include <vector>

using std::vector;

auto numSum = [](const auto&a){return ((a*(a+1))/2);};

vector<int> optimal_summands(int n) {
  vector<int> summands;
  //write your code here
  int i=1;
  while(numSum(i)<=n)
  {
    i++;
  }
  i--;

  if(i==1)
  {
    summands.push_back(n);
    return summands;
  }
  
  for(int j=0;j<i-1;j++)
  {
    summands.push_back(j+1);
  }
  summands.push_back(n - numSum(summands.back()));
  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
