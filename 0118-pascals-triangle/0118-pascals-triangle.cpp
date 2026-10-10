class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans(n);

        for (int i = 0; i < n; i++) {
            vector<int> row;
            int val = 1;
            row.push_back(val);

            for (int j = 1; j <= i; j++) {
                val = val * (i - j + 1) / j;
                row.push_back(val);
            }

            ans[i] = row;
        }

        return ans;
    }
};