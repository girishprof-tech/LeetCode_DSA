class Solution {
public:
    void recr(vector<string>& ans, string s, int n, int cnt) {
        if (cnt > n || cnt < 0) return;

        if (s.size() == 2 * n) {
            if (cnt == 0) ans.push_back(s);
            return;
        }

        recr(ans, s + "(", n, cnt + 1);
        recr(ans, s + ")", n, cnt - 1);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s = "(";
        
        recr(ans, s, n, 1);

        return ans;
    }
};