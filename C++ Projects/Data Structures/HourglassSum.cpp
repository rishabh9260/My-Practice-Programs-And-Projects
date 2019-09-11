#include <bits/stdc++.h>

using namespace std;

void CalculateSumOfHourglass(vector<vector<int>>&);

int main()
{
    vector<vector<int>> arr(6);
    for (int i = 0; i < 6; i++) {
        arr[i].resize(6);


        for (int j = 0; j < 6; j++) {
            cin >> arr[i][j];
        }
    
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    CalculateSumOfHourglass(arr);
    return 0;
}

void CalculateSumOfHourglass(vector<vector<int>>& arr1){
    int finalSum=0;
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            int sum = 0;
            for(int k=j; k<j+3; k++)
            {
                sum += arr1[i][k] + arr1[i+2][k];
            }
            sum += arr1[i+1][j+1];
            if(sum>finalSum)
            {
                finalSum = sum;
            }
            else if(sum<0 && j==0 && i==0)
            {
                    finalSum = sum;
            }
        }
    }
    cout<<finalSum;
}