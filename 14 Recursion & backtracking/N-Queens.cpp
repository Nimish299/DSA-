
#include <bits/stdc++.h>

using namespace std;
// class Solution
// {
// public:
//     bool issafe(int row, int col, vector<string> &board, int n)
//     {
//         // check upper element
//         int duprow = row;
//         int dupcol = col;

//         while (row >= 0 && col >= 0)
//         {
//             if (board[row][col] == 'Q')
//                 return false;
//             row--;
//             col--;
//         }

//         col = dupcol;
//         row = duprow;
//         while (col >= 0)
//         {
//             if (board[row][col] == 'Q')
//                 return false;
//             col--;
//         }

//         row = duprow;
//         col = dupcol;
//         while (row < n && col >= 0)
//         {
//             if (board[row][col] == 'Q')
//                 return false;
//             row++;
//             col--;
//         }
//         return true;
//     }
//     void solve(int col, int n, vector<vector<string>> &ans, vector<string> &board)
//     {
//         if (col == n)
//         {
//             ans.push_back(board);
//             return;
//         }
//         for (int row = 0; row < n; row++)
//         {
//             if (!issafe(row, col, board, n))
//             {
//                 board[row][col] = 'Q';
//                 solve(col + 1, n, ans, board);
//                 board[row][col] = '.';
//             }
//         }
//     }
//     vector<vector<string>> solveNQueens(int n)
//     {
//         vector<vector<string>> ans;
//         vector<string> board;
//         string s(n, '.');
//         for (int i = 0; i < n; i++)
//         {
//             board[i] = s;
//         }
//         solve(0, n, ans, board);
//         return ans;
//     }
// };

class Solution
{
public:
  void solve(int col, vector<string> &board, vector<vector<string>> &ans, vector<int> &leftrow, vector<int> &upperDiagonal, vector<int> &lowerDiagonal, int n)
  {
    if (col == n)
    {
      ans.push_back(board);
      return;
    }
    for (int row = 0; row < n; row++)
    {
      if (leftrow[row] == 0 && lowerDiagonal[row + col] == 0 && upperDiagonal[n - 1 + col - row] == 0)
      {
        board[row][col] = 'Q';
        leftrow[row] = 1;
        lowerDiagonal[row + col] = 1;
        upperDiagonal[n - 1 + col - row] = 1;
        solve(col + 1, board, ans, leftrow, upperDiagonal, lowerDiagonal, n);
        board[row][col] = '.';
        leftrow[row] = 0;
        lowerDiagonal[row + col] = 0;
        upperDiagonal[n - 1 + col - row] = 0;
      }
    }
  }

public:
  vector<vector<string>> solveNQueens(int n)
  {
    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n, '.');
    for (int i = 0; i < n; i++)
    {
      board[i] = s;
    }
    vector<int> leftrow(n, 0), upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0);
    solve(0, board, ans, leftrow, upperDiagonal, lowerDiagonal, n);
    return ans;
  }
};

int main()
{

  cout << "cc" << endl;
  int a, v;
  cin >> a;
  cin >> v;
  int c;
  cin >> c;
  if (c == 1)
    cout << a + v;
  else
    cout << a - v;
}
