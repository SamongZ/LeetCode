/*
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.

You may assume all four edges of the grid are all surrounded by water.

Example 1:

11110
11010
11000
00000
Answer: 1

Example 2:

11000
11000
00100
00011
Answer: 3
*/

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        rows = grid.size();
        if (rows == 0) return 0;
        cols = grid[0].size();
        int cnt = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == '1') {
                    check(grid, i, j);
                    ++cnt;
                }
            }
        }
        return cnt;
    }
private:
    void check(vector<vector<char>>& grid, int i, int j) {
        if (i < 0 || i >= rows || j < 0 || j >= cols || grid[i][j] == '0') return;
        grid[i][j] = '0';
        check(grid, i - 1, j);
        check(grid, i + 1, j);
        check(grid, i, j - 1);
        check(grid, i, j + 1);
    }
    int rows;
    int cols;
};
