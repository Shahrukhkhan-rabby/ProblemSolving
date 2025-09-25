#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        // dp stores the minimum path sum for the current row
        vector<int> dp(triangle.back()); // start with the last row

        // Start from the second last row and move upward
        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = 0; j <= i; j++)
            {
                dp[j] = triangle[i][j] + min(dp[j], dp[j + 1]);
            }
        }

        return dp[0]; // top element has the min path sum
    }
};
