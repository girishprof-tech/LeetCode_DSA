class Solution {
public:
    bool isSafe(vector<vector<char>>& board, int r, int c, char num) {
        for (int i = 0; i < 9; i++) {
            if (board[i][c] == num) return false;
        }

        for (int j = 0; j < 9; j++) {
            if (board[r][j] == num) return false;
        }

        r = (r / 3) * 3;
        c = (c / 3) * 3;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i + r][j + c] == num) return false;
            }
        }

        return true;
    }
    bool func(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {

            for (int j = 0; j < 9; j++) {

                if (board[i][j] == '.') {

                    for (char d = '1'; d <= '9'; d++) {

                        if (isSafe(board, i, j, d)) {

                            board[i][j] = d;

                            if (func(board)) return true;

                            board[i][j] = '.';
                        }
                    }

                    return false;
                }
            }
        }

        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        func(board);
    }
};