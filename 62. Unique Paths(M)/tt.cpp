/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time.

The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?


Above is a 3 x 7 grid. How many possible unique paths are there?

Note: m and n will be at most 100.
*/

// have a problem: time limited
class Solution1 {
public:
    int uniquePaths(int m, int n) {
        if (m == 1 || n == 1) return 1;
        return uniquePaths(m, n - 1) + uniquePaths(m - 1, n);
    }
};
// need m-1 down ways and n-1 right ways
class Solution2 {
public:
    int uniquePaths(int m, int n) {
        if (m == 1 || n == 1) return 1;
        long molecular = 1;
        long denominator = 1;
        for (int i = 1; i < min(m, n); ++i)
            denominator *= i;
        for (int j = max(m, n); j <= (m + n - 2); ++j)
            molecular *= j;
        return molecular / denominator;
    }
};
// DP problem
class Solution3 {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 1));
        for (int i = 1; i < m; ++i)
            for (int j = 1; j < n; ++j)
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        return dp[m - 1][n - 1];
    }
};
