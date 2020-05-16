#include <bits/stdc++.h>

using namespace std;

struct Segment
{
  int start, end;
};

vector<int> optimal_points(vector<Segment> &segments)
{
  vector<int> points;
  vector<Segment> res;
  //write your code here
  sort(segments.begin(), segments.end(),[](const auto& lhs, const auto& rhs) { return lhs.start < rhs.start; });
  res.push_back(segments[0]);
  for (size_t i = 0,j = 0; i < segments.size() - 1; ++i)
  {
    if(res[j].end >= segments[i+1].start)
    {
      res[j].end = min(segments[i+1].end,res[j].end);
      res[j].start = max(res[j].start,segments[i+1].start);
    }
    else
    {
      res.push_back(segments[i+1]);
      j++;
    }
  }
  for(size_t i = 0;i<res.size();i++)
  {
    points.push_back(res[i].end);
  }
  return points;
}

int main()
{
  int n;
  cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i)
  {
    cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i)
  {
    cout << points[i] << " ";
  }
}
