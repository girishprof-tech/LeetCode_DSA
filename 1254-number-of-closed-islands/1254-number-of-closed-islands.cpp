class Solution {
public:
    bool recr(vector<vector<int>>& grid, int r, int c) {
        if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size()) return false;

        if (grid[r][c] == 1)
            return true;

        grid[r][c] = 1;

        bool closed = !(r == 0 || r == grid.size() - 1 || c == 0 || c == grid[0].size() - 1);

        bool left = recr(grid, r, c - 1);
        bool right = recr(grid, r, c + 1);
        bool top = recr(grid, r - 1, c);
        bool bottom = recr(grid, r + 1, c);

        return closed && left && right && top && bottom;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int res = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1)
                    continue;

                res += recr(grid, i, j);
            }
        }

        return res;
    }
};