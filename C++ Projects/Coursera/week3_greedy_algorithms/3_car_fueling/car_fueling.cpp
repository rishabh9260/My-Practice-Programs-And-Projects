#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    // write your code here
    int numRefill = 0, currentRefill = 0, lastRefill = 0;
    while(currentRefill < stops.size()-1)
    {
        lastRefill = currentRefill;
        while(currentRefill < stops.size()-1 && stops[currentRefill+1]-stops[lastRefill] <= tank)
        {
            currentRefill++;
        }

        if(currentRefill==lastRefill)
            return -1;

        if(currentRefill<stops.size()-1)
        {
            numRefill++;
        }
    }
    return numRefill;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n+2);
    stops.at(0) = 0;
    for (size_t i = 1; i <= n; ++i)
        cin >> stops.at(i);
    stops.at(n+1) = d;
    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
