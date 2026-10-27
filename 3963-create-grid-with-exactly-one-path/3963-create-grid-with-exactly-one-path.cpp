class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> ans(m);

        string s = "";
        for (int i = 0; i < n; i++) {
            s += ".";
        }
        ans[0] = s;

        for (int i = 1; i < m; i++) {
            string st = "";

            for (int j = 0; j < n - 1; j++) {
                st += "#";
            }

            st += ".";
            ans[i] = st;
        }

        return ans;
    }
};