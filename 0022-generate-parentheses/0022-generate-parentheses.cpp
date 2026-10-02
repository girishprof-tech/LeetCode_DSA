class Solution {
public:
    void recr(vector<string>& ans, string s, int n, int cnt) {
        if (cnt > n || cnt < 0 || s.size() == 2 * n) {
            if (cnt == 0) ans.push_back(s);
            return;
        }

        s += '(';
        recr(ans, s, n, cnt + 1);
        s.pop_back();
        
        s += ')';
        recr(ans, s, n, cnt - 1);
        s.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s;
        s += '(';
        
        recr(ans, s, n, 1);

        return ans;
    }
};