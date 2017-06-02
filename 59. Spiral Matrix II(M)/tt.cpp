/*
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
*/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n, 0));
        int rowBeg = 0, colBeg = 0;
        int rowEnd = n - 1, colEnd = n - 1;
        int num = 1;
        while (rowBeg <= rowEnd && colBeg <= colEnd) {
            for (int j = colBeg; j <= colEnd; ++j)
                result[rowBeg][j] = num++;
            ++rowBeg;
            for (int i = rowBeg; i <= rowEnd; ++i)
                result[i][colEnd] = num++;
            --colEnd;
            if (rowBeg <= rowEnd) {
                for (int j = colEnd; j >= colBeg; -- j)
                    result[rowEnd][j] = num++;
                --rowEnd;
            }
            if (colBeg <= colEnd) {
                for (int i = rowEnd; i >= rowBeg; --i)
                    result[i][colBeg] = num++;
                ++colBeg;
            }
        }
        return result;
    }
};
