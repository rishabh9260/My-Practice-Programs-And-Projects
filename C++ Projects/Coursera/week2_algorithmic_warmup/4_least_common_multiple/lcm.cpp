#include <iostream>

int64_t gcd(int64_t a, int64_t b)
{
  if(b==0)
    return a;
  return gcd(b,a%b);
}

int64_t lcm(int64_t a, int64_t b) {
  int64_t div = gcd(a,b);
  a>b?(a = (a/div)):(b = (b/div));
  int64_t ans = (a*b);
  return ans;
}

int main() {
  int64_t a, b;
  std::cin >> a >> b;
  std::cout << lcm(a, b) << std::endl;
  return 0;
}
