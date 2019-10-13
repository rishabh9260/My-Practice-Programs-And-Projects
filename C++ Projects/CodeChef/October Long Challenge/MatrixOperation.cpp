#include<iostream>
using namespace std;
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, i;
    cin>>t;
    for(i=0; i<t; i++) // for TEST CASES
    {
        int n=0, m=0, q=0, counter=0;
        cin>>n>>m>>q;
        int matrix1[n+1][m+1] = {0};
        for(int j=0;j<q;j++) //for each operation
        {
            int x=0,y=0;
            cin>>x>>y;
            for(int i=1;i<=m;i++)// for row increment
            {
                 matrix1[x][i]=matrix1[x][i] +1;
                 if(matrix1[x][i]%2 != 0)
                     counter++;
                 else
                     counter--;
            }
            for(int j=1; j<=n;j++)// for column increment
            {
                matrix1[j][y]=matrix1[j][y] +1;
                if(matrix1[j][y]%2 != 0)
                     counter++;
                 else
                     counter--;
            }
        }
        // matrix manipulation done
         cout<<counter<<endl;
     }
  
  
} 