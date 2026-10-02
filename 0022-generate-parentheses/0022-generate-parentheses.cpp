class Solution {
public:
    void recr(vector<string>& ans, string s, int open, int close) {
        if (open == 0 && close == 0) {
            ans.push_back(s);
            return;
        }

        if (open > 0) {
            recr(ans, s + "(", open - 1, close);
        }

        if (close > open) {
            recr(ans, s + ")", open, close - 1);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        
        recr(ans, "", n, n);

        return ans;
    }
};