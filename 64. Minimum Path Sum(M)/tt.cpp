/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
*/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 1; i < m; ++i)
            grid[i][0] += grid[i - 1][0];
        for (int j = 1; j < n; ++j)
            grid[0][j] += grid[0][j - 1];
        for (int x = 1; x < m; ++x)
            for (int y = 1; y < n; ++y)
                grid[x][y] += min(grid[x - 1][y], grid[x][y - 1]);
        return grid[m - 1][n - 1];
    }
};
