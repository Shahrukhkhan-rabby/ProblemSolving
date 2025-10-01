#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int totalNQueens(int n)
    {
        int count = 0;
        vector<bool> col(n, false), diag1(2 * n - 1, false), diag2(2 * n - 1, false);

        function<void(int)> backtrack = [&](int row)
        {
            if (row == n)
            {
                count++;
                return;
            }
            for (int c = 0; c < n; c++)
            {
                if (col[c] || diag1[row - c + n - 1] || diag2[row + c])
                    continue;

                // Place queen
                col[c] = diag1[row - c + n - 1] = diag2[row + c] = true;
                backtrack(row + 1);
                // Remove queen
                col[c] = diag1[row - c + n - 1] = diag2[row + c] = false;
            }
        };

        backtrack(0);
        return count;
    }
};
