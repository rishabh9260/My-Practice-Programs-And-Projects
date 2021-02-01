#include <bits/stdc++.h>
using namespace std;

void printBoard(vector<vector<int>> &board, int n)
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if(i==0 && j==0)
                cout<<setw(3)<<" ";
            else if(i==0 && j>0)
                cout<<setw(3)<<(char)('a' + j - 1);
            else if(i>0 && j==0)
                cout<<setw(3)<<i;
            else
                cout<<setw(3)<<(board[i - 1][j - 1]?'Q':'X');
        }
        cout << endl;
    }
    cout<<endl;
}

bool isBoardValid(vector<vector<int>> &board, int row, int col, int n)
{
    for (int i = 0; i < col; i++)
        if (board[row][i])
            return false;
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;
    for (int i = row, j = col; j >= 0 && i < n; i++, j--)
        if (board[i][j])
            return false;
    return true;
}

bool NQueen(vector<vector<int>> &board, int col, int n)
{
    if (col >= n)
        return true;
    for (int i = 0; i < n; i++)
    {
        if (isBoardValid(board, i, col, n))
        {
            board[i][col] = 1;
            if (NQueen(board, col + 1, n))
                return true;
            board[i][col] = 0;
        }
    }
    return false;
}

bool checkSolutionExists(int n)
{
    vector<vector<int>> board(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            board[i][j] = 0;

    if (NQueen(board, 0, n) == false)
    {
        cout << "Solution does not exist";
        return false;
    }
    printBoard(board, n);
    return true;
}

int main()
{
    int n;
    cout << "\nEnter The size of the Board(n): ";
    cin >> n;
    cout << endl;
    if(checkSolutionExists(n))
        cout<<"This is one of the possible solutions for a Board of "<<n<<" X "<<n<<endl<<endl;
    return 0;
}