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
    bool func(vector<vector<char>>& board, int r, int c) {
        if (r == 9) return true;

        int nr = r;
        int nc = c + 1;

        if (c == 9) {
            nr = r + 1;
            nc = 0;
        }

        if (board[r][c] != '.') return func(board, nr, nc);

        for (char d = '1'; d <= '9'; d++) {
            if (isSafe(board, r, c, d)) {
                board[r][c] = d;
                if (func(board, nr, nc)) return true;
                board[r][c] = '.';
            }
        }

        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        func(board, 0, 0);
    }
};