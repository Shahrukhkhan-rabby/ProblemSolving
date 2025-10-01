#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> result;
        vector<string> board(n, string(n, '.'));

        // Track columns and diagonals
        vector<bool> col(n, false), diag1(2 * n - 1, false), diag2(2 * n - 1, false);

        function<void(int)> backtrack = [&](int row)
        {
            if (row == n)
            {
                result.push_back(board);
                return;
            }
            for (int c = 0; c < n; c++)
            {
                if (col[c] || diag1[row - c + n - 1] || diag2[row + c])
                    continue;

                // Place queen
                board[row][c] = 'Q';
                col[c] = diag1[row - c + n - 1] = diag2[row + c] = true;

                backtrack(row + 1);

                // Remove queen (backtrack)
                board[row][c] = '.';
                col[c] = diag1[row - c + n - 1] = diag2[row + c] = false;
            }
        };

        backtrack(0);
        return result;
    }
};
