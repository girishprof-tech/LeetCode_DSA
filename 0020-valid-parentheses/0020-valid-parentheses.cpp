class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            if (st.empty()) {
                if (s[i] == '(' || s[i] == '{' || s[i] == '[') st.push(s[i]);
                else return false;
            }
            else {
                if (st.top() == '(') {
                    if (s[i] == ')') st.pop();
                    else if (s[i] == '[' || s[i] == '{' || s[i] == '(') st.push(s[i]);
                    else return false;
                }
                else if (st.top() == '[') {
                    if (s[i] == ']') st.pop();
                    else if (s[i] == '[' || s[i] == '{' || s[i] == '(') st.push(s[i]);
                    else return false;
                }
                else {
                    if (s[i] == '}') st.pop();
                    else if (s[i] == '[' || s[i] == '{' || s[i] == '(') st.push(s[i]);
                    else return false;
                }
            }
        }

        if (st.empty()) return true;
        else return false;
    }
};