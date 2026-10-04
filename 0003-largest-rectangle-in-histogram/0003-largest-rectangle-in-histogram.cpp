class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        
        stack<int> st;
        int maxi = 0;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                int top = st.top();
                st.pop();
                int pse = st.empty() ? -1 : st.top();
                maxi = max(maxi, heights[top] * (i - pse - 1));
            }

            st.push(i);
        }

        while (!st.empty()) {
            int top = st.top();
            st.pop();

            int pse = st.empty() ? -1 : st.top();
            maxi = max(maxi, heights[top] * (n - pse - 1));
        }

        return maxi;
    }
};