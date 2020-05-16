#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using std::string;
using std::vector;

string largest_number(vector<string> a)
{
  //write your code here
  sort(a.begin(), a.end(), [](string x, string y) {
    string xy = x.append(y);
    string yx = y.append(x);
    return xy.compare(yx) > 0 ? 1 : 0;
  });
  std::stringstream ret;
  for (size_t i = 0; i < a.size(); i++)
  {
    ret << a[i];
  }
  string result;
  ret >> result;
  return result;
}

int main()
{
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++)
  {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}
