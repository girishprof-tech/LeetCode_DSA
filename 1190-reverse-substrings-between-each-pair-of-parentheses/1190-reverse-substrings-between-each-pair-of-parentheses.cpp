class Solution {
public:
    string reverseParentheses(string s) {
        string ans = "";
        stack<int> st;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') st.push(i);
            else if (s[i] == ')') {
                reverse(s.begin() + st.top() + 1, s.begin() + i);
                st.pop();
            }
        }

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == ')') continue;

            ans += s[i];
        }

        return ans;
    }
};