class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> ans(n);

        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && prices[st.top()] > prices[i]) {
                st.pop();
            }

            if (st.empty()) {
                ans[i] = prices[i];
            }
            else {
                ans[i] = prices[i] - prices[st.top()];
            }

            st.push(i);
        }

        return ans;
    }
};