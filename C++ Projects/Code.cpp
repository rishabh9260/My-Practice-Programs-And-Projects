#include<bits/stdc++.h>
using namespace std;
int segmentsCovering(vector<vector<int>> segments)
{
    sort(segments.begin(),segments.end());
    // for(int i=0;i<segments.size();i++)
    // {
    //     for(int j=0;j<2;j++)
    //     {
    //         cout<<segments[i][j]<<"\t";
    //     }
    //     cout<<endl;
    // }
    vector<vector<int>> overlap;
    overlap.push_back(segments[0]);
    for(int i=1,j=0;i<segments.size();i++)
    {
        if(segments[i][0] <= overlap[j][1])
        {
            overlap[j][0] = segments[i][0];
        }
        else
        {
            overlap.push_back(segments[i]);
            j++;
        }
        
    }
    // for(int i=0;i<overlap.size();i++)
    // {
    //     for(int j=0;j<2;j++)
    //     {
    //         cout<<overlap[i][j]<<"\t";
    //     }
    //     cout<<endl;
    // }
    return 0;
}

int main()
{
    vector<vector<int>> segments = {{-1, 3},
            {-5, -3},
            {3, 5},
            {2, 4},
            {-3, -2},
            {-1, 4},
            {5, 5}};
segmentsCovering(segments);
return 0;    
}
