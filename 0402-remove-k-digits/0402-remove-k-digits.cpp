class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        if (n <= k) return "0";
        if (k <= 0) return num;
        
        string ans = "";
        stack<char> st;

        for (int i = 0; i < n; i++) {
            while (k > 0 && !st.empty() && num[i] < st.top()) {
                k--;
                st.pop();
            }

            st.push(num[i]);

            if (st.size() == 1 && num[i] == '0') st.pop();
        }

        while (k != 0 && !st.empty()) {
            st.pop();
            k--;
        }

        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        int m = ans.size();
        for (int i = 0; i < m / 2; i++) {
            int temp = ans[i];
            ans[i] = ans[m - i - 1];
            ans[m - i - 1] = temp;
        }

        if (ans.length() == 0) return "0";

        return ans;
    }
};