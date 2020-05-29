#include<bits/stdc++.h>
using namespace std;

vector<int> fast_count_segments(vector<pair<int,int>> starts, vector<pair<int,int>> ends, vector<pair<int,int>> points) {
  vector<int> cnt(points.size());
  map<int,int> point_count;
  //write your code here
  vector<pair<int,int>> line;
  copy(starts.begin(), starts.end(), back_inserter(line));
	copy(points.begin(), points.end(), back_inserter(line));
	copy(ends.begin(), ends.end(), back_inserter(line));
  stable_sort(line.begin(),line.end());

  int count = 0;
  for(int i = 0;i<line.size();i++)
  {
    if(line[i].second == 0)
      count++;
    else if(line[i].second == 2)
      count --;
    if(line[i].second == 1)
      point_count[line[i].first] = count;
  }
  for(int i=0;i<points.size();i++)
    cnt[i] = point_count[points[i].first];

  return cnt;
}

// vector<int> naive_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
//   vector<int> cnt(points.size());
//   for (size_t i = 0; i < points.size(); i++) {
//     for (size_t j = 0; j < starts.size(); j++) {
//       cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
//     }
//   }
//   return cnt;
// }

int main() {
  int n, m;
  cin >> n >> m;
  vector<pair<int,int>> starts(n), ends(n);
  for (size_t i = 0; i < starts.size(); i++) {
    int a,b;
    cin>>a>>b;
    starts[i] = (make_pair(a,0));
    ends[i] = (make_pair(b,2));
  }
  vector<pair<int,int>> points(m);
  for (size_t i = 0; i < points.size(); i++) {
    int x;
    cin >> x;
    points[i] = (make_pair(x,1));
  }
  //use fast_count_segments
  vector<int> cnt = fast_count_segments(starts, ends, points);
  for (size_t i = 0; i < cnt.size(); i++) {
    cout << cnt[i] << ' ';
  }
}
