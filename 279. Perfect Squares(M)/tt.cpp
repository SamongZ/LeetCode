/*
Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13, return 2 because 13 = 4 + 9.
*/

class Solution {
public:
    int numSquares(int n) {
        vector<int> numCnt(n + 1, INT_MAX);
        numCnt[0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j * j <= i; ++j)
                numCnt[i] = min(numCnt[i], numCnt[i - j * j] + 1);
        }
        return numCnt[n];
    }
};
