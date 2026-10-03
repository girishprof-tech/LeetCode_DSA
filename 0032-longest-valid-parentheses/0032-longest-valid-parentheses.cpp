class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        stack<int> st;
        int start = -1;
        int maxi = 0;
        
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                st.push(i);
            } 
            else {
                if (st.empty()) {
                    start = i;
                }
                else if (st.size() == 1) {
                    st.pop();
                    maxi = max(maxi, i - start);
                }
                else {
                    st.pop();
                    maxi = max(maxi, i - st.top());
                }
            }
        }

        return maxi;
    }
};