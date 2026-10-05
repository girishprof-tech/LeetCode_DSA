class Solution {
public:
    int scoreOfParentheses(string& s) {
        int n = s.length();
        stack<pair<int, int>> st;
        stack<int> braces;

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                braces.push(i);
            }
            else {
                if (s[i - 1] == '(') {
                    st.push({i - 1, 1});
                    braces.pop();
                }
                else {
                    pair<int, int> top = st.top();
                    st.pop();
                    st.push({braces.top(), 2 * top.second});
                    braces.pop();
                }

                if (!st.empty() && st.top().first != 0 &&  s[st.top().first - 1] == ')') {
                    pair<int, int> top1 = st.top();
                    st.pop();
                    pair<int, int> top2 = st.top();
                    st.pop();
                    st.push({top2.first, top1.second + top2.second});
                }
            }
        }

        return st.top().second;
    }
};