#include <bits/stdc++.h>
using namespace std;

string SudokuQuadrantChecker(string strArr[], int arrLength) {
  
  // code goes here
  int board[arrLength][9];
  for(int i=0;i<arrLength;i++)
  {
    for(int j=0;j<9;j++)
    {
      if(strArr[i][j+1]=='x')
        board[i][j] = -1;
      else
        board[i][j] = int(strArr[i][j+1] - '0');
    }
  }
  for(int i=0;i<arrLength;i++)
  {
    for(int j=0;j<9;j++)
    {
      cout<<board[i][j]<<"  ";
    }
    cout<<endl;
  }
  for(int i=0;i<arrLength;i++)
  {
    for(int j=0;j<9;j++)
    {
      cout<<strArr[i][j+1]<<"  ";
    }
    cout<<endl;
  }
  return strArr[0];
}

int main(void) { 
   
  // keep this function call here
  /* Note: In C++ you first have to initialize an array and set 
     it equal to the stdin to test your code with arrays. */

  string A[] = {"(1,2,3,4,5,6,7,8,1)","(x,x,x,x,x,x,x,x,x)","(x,x,x,x,x,x,x,x,x)","(1,x,x,x,x,x,x,x,x)","(x,x,x,x,x,x,x,x,x)","(x,x,x,x,x,x,x,x,x)","(x,x,x,x,x,x,x,x,x)","(x,x,x,x,x,x,x,x,x)","(x,x,x,x,x,x,x,x,x)"};
  int arrLength = sizeof(A) / sizeof(*A);
  cout << SudokuQuadrantChecker(A, arrLength);
  return 0;
}