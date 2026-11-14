class Solution {
public:
    void dfs(vector<vector<char>>& grid, vector<vector<int>>& visited, int r, int c) {
        int m = grid.size();
        int n = grid[0].size();

        if (r < 0 || r >= m || c < 0 || c >= n || visited[r][c] == 1 || grid[r][c] == '0') return;

        visited[r][c] = 1;

        dfs(grid, visited, r - 1, c);
        dfs(grid, visited, r + 1, c);
        dfs(grid, visited, r, c - 1);
        dfs(grid, visited, r, c + 1);
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> visited(m, vector<int>(n, 0));
        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1' && visited[i][j] == 0) {
                    ans++;
                    dfs(grid, visited, i, j);
                }
            }
        }

        return ans;
    }
};