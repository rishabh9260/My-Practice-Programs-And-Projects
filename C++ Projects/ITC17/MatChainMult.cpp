#include<bits/stdc++.h>
using namespace std;

void printParenthesis(int i, int j, vector<vector<int>> kMat, char &name);
 
int matChain(int n, int order[])
{
    int dp[n+1][n+1];
    vector<vector<int>> kMat(n+1, vector<int>(n+1));
    for(int i=1;i<=n;i++)
    {
        dp[i][i] = 0;
    }
 
    for(int range=2;range<=n;range++)
    {
        for(int i=1;i<=(n-range+1);i++)
        {
            int j = i+range-1;

            dp[i][j] = INT_MAX;
 
            for(int k=i;k<j;k++)
            {
                int tempValue = dp[i][k]+dp[k+1][j]+order[i-1]*order[k]*order[j];
 
                if(tempValue<dp[i][j])
                {
                    dp[i][j] = tempValue;
                    kMat[i][j] = k;
                }
            }
        }
    }

    cout<<"The DP matrix is:\n";
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(j<i)
            {
                cout<<"  \t";
                continue;
            }
            cout<<dp[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<"The K matrix is:\n";
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(j<=i)
            {
                cout<<"  \t";
                continue;
            }
            cout<<kMat[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<"The final expression is: ";
    char ch = 'A';
    printParenthesis(1, n, kMat, ch);
    cout<<endl;
    return dp[1][n];
}

void printParenthesis(int i, int j, vector<vector<int>> kMat, char &name) 
{
    if (i == j) 
    { 
        cout<<name++; 
        return; 
    }
    cout<<"("; 
    printParenthesis(i, kMat[i][j], kMat, name);  
    printParenthesis(kMat[i][j] + 1, j, kMat, name); 
    cout<<")"; 
} 
 
int main()
{
    int n;
    cout<<"Enter the number of matrices in the chain (n>1): ";
    cin>>n;

    int order[n+1];
    cout<<"Enter the order array of the matrix chain i.e. values of d ("<<n+1<<" elements): ";
    for(int i=0;i<=n;i++)
    {
        cin>>order[i];
    }

    int minMult = matChain(n,order);
    cout<<"The minimum number of multiplication operations required to multiply the matrix chain is: "<<minMult;
    cout<<endl;
    return 0;
}