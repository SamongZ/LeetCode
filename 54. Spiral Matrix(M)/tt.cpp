/*
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if (matrix.size() == 0)
            return result;
        int rowBeg = 0;
        int colBeg = 0;
        int rowEnd = matrix.size() - 1;
        int colEnd = matrix[0].size() - 1;
        while (rowBeg <= rowEnd && colBeg <= colEnd) {
            for (int j = colBeg; j <= colEnd; ++j)
                result.push_back(matrix[rowBeg][j]);
            ++rowBeg;
            for (int i = rowBeg; i <= rowEnd; ++i)
                result.push_back(matrix[i][colEnd]);
            --colEnd;
            if (rowBeg <= rowEnd) {
                for (int j = colEnd; j >= colBeg; --j)
                    result.push_back(matrix[rowEnd][j]);
                --rowEnd;
            }
            if (colBeg <= colEnd) {
                for (int i = rowEnd; i >= rowBeg; --i)
                    result.push_back(matrix[i][colBeg]);
                ++colBeg;
            }
        }
        return result;
    }
};
