#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int m, n;
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        m = heights.size();
        n = heights[0].size();

        vector<vector<int>> pacific(m, vector<int>(n, 0));
        vector<vector<int>> atlantic(m, vector<int>(n, 0));

        // DFS from Pacific (top row & left col) and Atlantic (bottom row & right col)
        for (int i = 0; i < m; i++)
        {
            dfs(heights, pacific, i, 0);      // left edge (Pacific)
            dfs(heights, atlantic, i, n - 1); // right edge (Atlantic)
        }
        for (int j = 0; j < n; j++)
        {
            dfs(heights, pacific, 0, j);      // top edge (Pacific)
            dfs(heights, atlantic, m - 1, j); // bottom edge (Atlantic)
        }

        vector<vector<int>> result;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (pacific[i][j] && atlantic[i][j])
                {
                    result.push_back({i, j});
                }
            }
        }
        return result;
    }

    void dfs(vector<vector<int>> &heights, vector<vector<int>> &visited, int r, int c)
    {
        visited[r][c] = 1;
        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (auto [dr, dc] : dirs)
        {
            int nr = r + dr, nc = c + dc;
            if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                continue;
            // can flow only if next cell is higher or equal
            if (!visited[nr][nc] && heights[nr][nc] >= heights[r][c])
            {
                dfs(heights, visited, nr, nc);
            }
        }
    }
};
