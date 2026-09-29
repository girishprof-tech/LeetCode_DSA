class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size();
        int n = box[0].size();

        vector<vector<char>> ans(n, vector<char>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans[i][j] = box[m - j - 1][i];
            }
        }

        for (int j = m - 1; j >= 0; j--) {
            int cnt = 0;
            for (int i = n - 1; i >= 0; i--) {
                if (ans[i][j] == '.') cnt++;
                else if (ans[i][j] == '*') cnt = 0;
                else {
                    if (cnt != 0) {
                        ans[i + cnt][j] = ans[i][j];
                        ans[i][j] = '.';
                        
                    }
                }
            }
        }

        return ans;
    }
};