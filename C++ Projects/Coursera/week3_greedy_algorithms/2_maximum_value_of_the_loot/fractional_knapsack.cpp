#include <bits/stdc++.h>

using namespace std;

bool sortinrev(const pair<double, int> &a, const pair<double, int> &b)
{
  return (a.first > b.first);
}

double get_optimal_value(int capacity, vector<int> weights, vector<int> values, int n)
{
  double value = 0.0;

  vector<pair<double, int>> per_unit(n);
  for (int i = 0; i < n; i++)
  {
    per_unit[i].first = ((double)values[i] / (double)weights[i]);
    per_unit[i].second = i;
  }
  sort(per_unit.begin(), per_unit.end(), sortinrev);
  int i = 0;
  while (i<n)
  {
    if(capacity == 0)
      return value;
    int a = min(capacity,weights[per_unit[i].second]);
    value += a*per_unit[i].first;
    weights[per_unit[i].second] -= a;
    capacity -= a;
    i++;
  }
  return value;
}

int main()
{
  int n;
  int capacity;
  cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++)
  {
    cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values, n);

  cout.precision(10);
  cout <<fixed<< optimal_value << std::endl;
  return 0;
}
