class Solution {
public:
    struct PairHash {
        size_t operator()(const pair<int, int>& p) const {
            size_t h1 = hash<int>{}(p.first);
            size_t h2 = hash<int>{}(p.second);

            return h1 ^ (h2 + 0x9e3779b9 + (h1 << 6) + (h1 >> 2));
        }
    };
    bool recr(vector<vector<int>>& grid, unordered_set<pair<int, int>, PairHash>& seen, int r, int c) {
        if (grid[r][c] == 1 || seen.count({r, c}) != 0)
            return true;

        if (r == 0 || r == grid.size() - 1 || c == 0 || c == grid[0].size() - 1)
            return false;

        seen.insert({r, c});

        bool left = recr(grid, seen, r, c - 1);
        bool right = recr(grid, seen, r, c + 1);
        bool top = recr(grid, seen, r - 1, c);
        bool bottom = recr(grid, seen, r + 1, c);

        return left && right && top && bottom;
    }
    int closedIsland(vector<vector<int>>& grid) {
        unordered_set<pair<int, int>, PairHash> seen;
        int res = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1 || seen.count({i, j}) != 0)
                    continue;

                res += recr(grid, seen, i, j);
            }
        }

        return res;
    }
};