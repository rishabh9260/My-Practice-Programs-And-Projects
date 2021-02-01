#include <bits/stdc++.h>
using namespace std;

template <typename Iterator>
Iterator compress(const string &uncompressed, Iterator result)
{

  int dictSize = 256;
  map<string,int> dictionary;
  for (int i = 0; i < 256; i++)
    dictionary[string(1, i)] = i;
 
  string w;
  for (string::const_iterator it = uncompressed.begin(); it != uncompressed.end(); ++it) 
  {
    char c = *it;
    string wc = w + c;
    if (dictionary.count(wc))
      w = wc;
    else 
    {
      *result++ = dictionary[w];
      dictionary[wc] = dictSize++;
      w = string(1, c);
    }
  }
 
  if (!w.empty())
    *result++ = dictionary[w];
  return result;
}
 
template <typename Iterator>
string decompress(Iterator begin, Iterator end)
{
  int dictSize = 256;
  map<int,string> dictionary;
  for (int i = 0; i < 256; i++)
    dictionary[i] = string(1, i);
 
  string w(1, *begin++);
  string result = w;
  string entry;
  for ( ; begin != end; begin++) 
  {
    int k = *begin;
    if (dictionary.count(k))
      entry = dictionary[k];
    else if (k == dictSize)
      entry = w + w[0];
    else
      throw "Bad compressed k";
 
    result += entry;
 
    dictionary[dictSize++] = w + entry[0];
 
    w = entry;
  }
  return result;
}
 
int main()
{
  vector<int> compressed;
  compress("Mask is the new normal", back_inserter(compressed));
  copy(compressed.begin(), compressed.end(), ostream_iterator<int>(cout, ", "));
  cout << endl;
  string decompressed = decompress(compressed.begin(), compressed.end());
  cout << decompressed << endl;
 
  return 0;
}