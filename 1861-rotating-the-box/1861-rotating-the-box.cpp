class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size();
        int n = box[0].size();
        vector<vector<char>> ans(n, vector<char>(m));

        for (int j = m - 1; j >= 0; j--) {
            int cnt = 0;
            int row = m - j - 1;

            for (int i = n - 1; i >= 0; i--) {
                if (box[row][i] == '.') { 
                    ans[i][j] = '.';
                    cnt++;
                }
                else if (box[row][i] == '*') {
                    cnt = 0;
                    ans[i][j] = '*';
                }
                else {
                    if (cnt != 0) {
                        ans[i + cnt][j] = box[row][i];
                        ans[i][j] = '.';
                    }
                    else {
                        ans[i][j] = '#';
                    }
                }
            }
        }

        return ans;
    }
};