class Solution {
public:
    void func(vector<vector<string>>& ans, vector<string>& board, int n, int c, vector<int>& left, vector<int>& upper, vector<int>& lower) {
        if (n == c) {
            ans.push_back(board);
            return;
        }

        for (int r = 0; r < n; r++) {
            if (left[r] == 0 && upper[n - 1 + c - r] == 0 && lower[r + c] == 0) {
                board[r][c] = 'Q';
                left[r] = 1;
                upper[n - 1 + c - r] = 1;
                lower[r + c] = 1;

                func(ans, board, n, c + 1, left, upper, lower);

                board[r][c] = '.';
                left[r] = 0;
                upper[n - 1 + c - r] = 0;
                lower[r + c] = 0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        vector<int> left(n, 0), upper(2 * n - 1, 0), lower(2 * n - 1, 0);
        func(ans, board, n, 0, left, upper, lower);
        return ans;
    }
};