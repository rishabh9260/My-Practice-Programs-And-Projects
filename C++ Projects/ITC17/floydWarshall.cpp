#include <bits/stdc++.h>
using namespace std;

void floydWarshall(vector<vector<int>> b, int n)
{
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i != j)
                    b[i][j] = min(b[i][j], b[i][k] + b[k][j]);
            }
        }
    }               

    cout<<"\nThe value of the matrix is: \n\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(b[i][j] == 9999)
                cout<<setw(4)<<"INF";
            else
                cout<<setw(4)<<b[i][j];
        }
        cout<<endl;
    }
}
int main()
{
    int n;
    cout<<"Enter the number of vertices in the graph: ";
    cin>>n;
    vector<vector<int>> b(n, vector<int>(n));
    cout<<"\nENTER VALUES OF ADJACENCY MATRIX (ENTER 9999 for INFINITY)\n\n";
    for (int i = 0; i < n; i++)
    {
        cout<<"Enter values for row "<<(i+1)<<endl;
        for (int j = 0; j < n; j++)
        {
            cin>>b[i][j];
        }
    }
    floydWarshall(b, n);
    return 0;
}