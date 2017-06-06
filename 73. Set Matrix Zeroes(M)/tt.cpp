/*
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> row;   // record the rows that need to be changed
        set<int> col;   // record the columns that need to be changed
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (matrix[i][j] == 0) {
                    row.insert(i);
                    col.insert(j);
                }
            }
        }
        // change the rows
        for (int p = 0; p < matrix.size(); ++p) {
            if (row.find(p) != row.end()) {
                for (int q = 0; q < matrix[0].size(); ++q)
                    matrix[p][q] = 0;
            }
        }
        // change the columns
        for (int qq = 0; qq < matrix[0].size(); ++qq) {
            if (col.find(qq) != col.end()) {
                for (int pp = 0; pp < matrix.size(); ++pp)
                    matrix[pp][qq] = 0;
            }
        }
    }
};
