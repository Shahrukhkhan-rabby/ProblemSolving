#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int swimInWater(vector<vector<int>> &grid)
    {
        int n = grid.size();
        vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        // Min-heap: (time, x, y)
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({grid[0][0], 0, 0});

        vector<vector<int>> visited(n, vector<int>(n, 0));
        visited[0][0] = 1;

        while (!pq.empty())
        {
            auto cur = pq.top();
            pq.pop();
            int t = cur[0], x = cur[1], y = cur[2];

            if (x == n - 1 && y == n - 1)
                return t; // reached destination

            for (auto &d : dirs)
            {
                int nx = x + d[0], ny = y + d[1];
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny])
                {
                    visited[nx][ny] = 1;
                    // max time so far must include this cell’s elevation
                    pq.push({max(t, grid[nx][ny]), nx, ny});
                }
            }
        }

        return -1; // should never happen
    }
};
