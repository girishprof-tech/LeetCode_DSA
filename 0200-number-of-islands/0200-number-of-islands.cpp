class Solution {
public:
    void dfs(vector<vector<char>>& grid, vector<vector<int>>& visited, int r, int c) {
        if (visited[r][c] != 0) return;
        visited[r][c] = 1;

        if (r > 0 && grid[r - 1][c] == '1') dfs(grid, visited, r - 1, c);
        if (r < grid.size() - 1 && grid[r + 1][c] == '1') dfs(grid, visited, r + 1, c);
        if (c > 0 && grid[r][c - 1] == '1') dfs(grid, visited, r, c - 1);
        if (c < grid[0].size() - 1 && grid[r][c + 1] == '1') dfs(grid, visited, r, c + 1);
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n));
        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (visited[i][j] == 0 && grid[i][j] == '1') {
                    ans++;
                    dfs(grid, visited, i, j);
                }
            }
        }

        return ans;
    }
};