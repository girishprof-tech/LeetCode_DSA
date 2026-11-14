class Solution {
public:
    void recr(vector<vector<char>>& grid, vector<vector<int>>& visited, int r, int c, int m, int n) {
        if (visited[r][c]) return;

        visited[r][c] = 1;

        if (r > 0 && grid[r - 1][c] == '1') recr(grid, visited, r - 1, c, m, n);
        if (r < m - 1 && grid[r + 1][c] == '1') recr(grid, visited, r + 1, c, m, n);
        if (c > 0 && grid[r][c - 1] == '1') recr(grid, visited, r, c - 1, m, n);
        if (c < n - 1 && grid[r][c + 1] == '1') recr(grid, visited, r, c + 1, m, n);
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n));
        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j] && grid[i][j] == '1') {
                    ans++;
                    recr(grid, visited, i, j, m, n);
                }
            }
        }

        return ans;
    }
};