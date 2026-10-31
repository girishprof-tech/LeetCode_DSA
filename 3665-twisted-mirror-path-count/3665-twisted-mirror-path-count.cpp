class Solution {
public:
    const int MOD = 1e9 + 7;

    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> down(n + 1, 0);
        vector<int> right(n + 1, 0);

        for (int r = m - 1; r >= 0; r--) {
            for (int c = n - 1; c >= 0; c--) {

                if (r == m - 1 && c == n - 1) {
                    down[c] = right[c] = 1;
                    continue;
                }

                int d = down[c];
                int rt = (c + 1 < n) ? right[c + 1] : 0;

                if (grid[r][c] == 1) {
                    down[c] = rt;
                    right[c] = d;
                }
                else {
                    down[c] = (d + rt) % MOD;
                    right[c] = (d + rt) % MOD;
                }
            }
        }

        return right[0];
    }
};