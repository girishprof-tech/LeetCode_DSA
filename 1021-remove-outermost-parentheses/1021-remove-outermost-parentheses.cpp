class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int cnt = 0;
        int ind = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                cnt++;
                if (cnt == 1) {
                    ind = i + 1;
                }
            }
            else {
                if (cnt == 1) {
                    ans += s.substr(ind, i - ind);
                }
                cnt--;
            }
        }

        return ans;
    }
};