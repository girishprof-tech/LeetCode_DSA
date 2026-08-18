class Solution {
public:
    bool isSafe(int r, int c, vector<string>& board, int n) {
        for (int j = c; j >= 0; j--) {
            if (board[r][j] == 'Q') return false;
        }

        for (int i = r, j = c; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') return false;
        }

        for (int i = r, j = c; i < n && j >= 0; i++, j--) {
            if (board[i][j] == 'Q') return false;
        }

        return true;
    }
    void func(vector<vector<string>>& ans, vector<string>& board, int n, int c) {
        if (n == c) {
            ans.push_back(board);
            return;
        }

        for (int r = 0; r < n; r++) {
            if (isSafe(r, c, board, n)) {
                board[r][c] = 'Q';
                func(ans, board, n, c + 1);
                board[r][c] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        func(ans, board, n, 0);
        return ans;
    }
};