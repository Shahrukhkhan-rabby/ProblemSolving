#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int trapRainWater(vector<vector<int>> &heightMap)
    {
        int m = heightMap.size(), n = heightMap[0].size();
        if (m <= 2 || n <= 2)
            return 0; // no space to trap water

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        priority_queue<vector<int>, vector<vector<int>>, greater<>> minHeap;

        // Step 1: push all boundary cells into heap
        for (int i = 0; i < m; i++)
        {
            minHeap.push({heightMap[i][0], i, 0});
            minHeap.push({heightMap[i][n - 1], i, n - 1});
            visited[i][0] = visited[i][n - 1] = true;
        }
        for (int j = 0; j < n; j++)
        {
            minHeap.push({heightMap[0][j], 0, j});
            minHeap.push({heightMap[m - 1][j], m - 1, j});
            visited[0][j] = visited[m - 1][j] = true;
        }

        // directions for 4 neighbors
        vector<int> dirs = {0, 1, 0, -1, 0};
        int water = 0;

        // Step 2: process heap
        while (!minHeap.empty())
        {
            auto cell = minHeap.top();
            minHeap.pop();
            int h = cell[0], x = cell[1], y = cell[2];

            for (int d = 0; d < 4; d++)
            {
                int nx = x + dirs[d], ny = y + dirs[d + 1];
                if (nx < 0 || ny < 0 || nx >= m || ny >= n || visited[nx][ny])
                    continue;

                visited[nx][ny] = true;
                water += max(0, h - heightMap[nx][ny]); // trapped water
                minHeap.push({max(heightMap[nx][ny], h), nx, ny});
            }
        }

        return water;
    }
};
