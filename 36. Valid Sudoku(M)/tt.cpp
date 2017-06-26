/*
Determine if a Sudoku is valid.
The Sudoku board could be partially filled, where empty cells are filled with the character '.'.

Note:
A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.
*/

class Solution1 {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        if (board.size() != 9 || board[0].size() != 9) return false;
        for (int i = 0; i < 9; ++i) {
            map<char, int> reRow;
            map<char, int> reCol;
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] > '0' && board[i][j] <= '9') {
                    if (reRow[board[i][j]] == 0) ++reRow[board[i][j]];
                    else return false;
                }
                if (board[j][i] > '0' && board[j][i] <= '9') {
                    if (reCol[board[j][i]] == 0) ++reCol[board[j][i]];
                    else return false;
                }
            }
        }
        for (int p = 0; p < 3; ++p) {
            for (int q = 0; q < 3; ++q) {
                map<char, int> refer;
                for (int i = p * 3; i < p * 3 + 3; ++i) {
                    for (int j = q * 3; j < q * 3 + 3; ++j) {
                        if (board[i][j] > '0' && board[i][j] <= '9') {
                            if (refer[board[i][j]] == 0) ++refer[board[i][j]];
                            else return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};

/*
Three flags are used to check whether a number appear.

used1: check each row

used2: check each column

used3: check each sub-boxes
*/
class Solution2 {
public:
    bool isValidSudoku(vector<vector<char> > &board)
    {
        int used1[9][9] = {0}, used2[9][9] = {0}, used3[9][9] = {0};

        for(int i = 0; i < board.size(); ++ i)
            for(int j = 0; j < board[i].size(); ++ j)
                if(board[i][j] != '.')
                {
                    int num = board[i][j] - '0' - 1, k = i / 3 * 3 + j / 3;
                    if(used1[i][num] || used2[j][num] || used3[k][num])
                        return false;
                    used1[i][num] = used2[j][num] = used3[k][num] = 1;
                }
        return true;
    }
};
