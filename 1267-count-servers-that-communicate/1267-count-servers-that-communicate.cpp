class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        set<pair<int, int>> row;
        int res = 0;

        for (int i = 0; i < m; i++) {
            int sum = 0;

            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) sum++;
            }

            if (sum >= 2) {
                res += sum;

                for (int j = 0; j < n; j++) {
                    if (grid[i][j] == 1) {
                        row.insert({i, j});
                    }
                }
            }
        }

        for (int j = 0; j < n; j++) {
            int sum = 0;

            for (int i = 0; i < m; i++) {
                if (grid[i][j] == 1) sum++;
            }

            if (sum >= 2) {
                for (int i = 0; i < m; i++) {
                    if (grid[i][j] == 1 && row.find({i, j}) != row.end()) {
                        sum--;
                    }
                }

                res += sum;
            }
        }

        return res;
    }
};