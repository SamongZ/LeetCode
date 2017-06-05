/*
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).
*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int index = matrix.size() - 1;
        for (int i = 0; i <= index / 2; ++i) {
            for (int j = i; j < index - i; ++j) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[index - j][i];
                matrix[index - j][i] = matrix[index - i][index - j];
                matrix[index - i][index - j] = matrix[j][index - i];
                matrix[j][index - i] = temp;
            }
        }
    }
};
