class Solution {
public:
    long long recr(vector<vector<int>>& grid, int r, int c) {
        if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size()) return 0;
        if (grid[r][c] == 0) return 0;

        long long curr = grid[r][c];
        grid[r][c] = 0;

        long long left = recr(grid, r, c - 1);
        long long right = recr(grid, r, c + 1);
        long long top = recr(grid, r - 1, c);
        long long bottom = recr(grid, r + 1, c);

        return curr + top + bottom + left + right;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        if (grid.size() <= 0 || grid[0].size() <= 0) return 0;

        int m = grid.size();
        int n = grid[0].size();
        int res = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0) {
                    long long val = recr(grid, i, j);
                    if (val % k == 0) res++;
                }
            }
        }

        return res;
    }
};