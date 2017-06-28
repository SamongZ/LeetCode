/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell,
where "adjacent" cells are those horizontally or vertically neighboring.
The same letter cell may not be used more than once.

For example,
Given board =

[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
*/

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.size() == 0) return false;
        int row = board.size();
        int col = board[0].size();
        vector<vector<int>> used(row, vector<int>(col, 0));
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (find(board, used, row, col, i, j, word, 0))
                    return true;
            }
        }
        return false;
    }
private:
    bool find(vector<vector<char>>& board, vector<vector<int>> &used, int row, int col, int i, int j, const string &word, int k) {
        if (k == word.size())
            return true;
        if (i < 0 || i >= row || j < 0 || j >= col || board[i][j] != word[k] || used[i][j] != 0)
            return false;
        used[i][j] = 1;
        if (find(board, used, row, col, i - 1, j, word, k + 1) || find(board, used, row, col, i + 1, j, word, k + 1) ||
            find(board, used, row, col, i, j - 1, word, k + 1) || find(board, used, row, col, i, j + 1, word, k + 1))
            return true;
        used[i][j] = 0;
        return false;
    }
};
