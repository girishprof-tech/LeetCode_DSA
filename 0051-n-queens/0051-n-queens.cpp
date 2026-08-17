class Solution {
public:
    bool isSafe(vector<vector<char>> board, int row, int col, int n) {
        for (int j = 0; j < n; j++) {
            if (board[row][j] == 'Q') return false;
        }

        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') return false;
        }

        for (int i = row, j = col; i < n && j >= 0; i++, j--) {
            if (board[i][j] == 'Q') return false;
        }

        return true;
    }
    void func(vector<vector<string>>& ans, vector<vector<char>>& board, int n, int c) {
        if (n == c) {
            vector<string> temp;

            for (int i = 0; i < n; i++) {
                string row(board[i].begin(), board[i].end());
                temp.push_back(row);
            }

            ans.push_back(temp);
            return;
        }

        for (int r = 0; r < n; r++) {
            if (isSafe(board, r, c, n)) {
                board[r][c] = 'Q';
                func(ans, board, n, c + 1);
                board[r][c] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<vector<char>> board(n, vector<char>(n, '.'));
        func(ans, board, n, 0);
        return ans;
    }
};