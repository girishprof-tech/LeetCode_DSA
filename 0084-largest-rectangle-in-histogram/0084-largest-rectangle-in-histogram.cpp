class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        
        stack<int> st;
        vector<int> nextSmaller(n);
        vector<int> prevSmaller(n);

        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) st.pop();

            if (st.empty()) prevSmaller[i] = -1;
            else prevSmaller[i] = st.top();

            st.push(i);
        }

        while (!st.empty()) {
            st.pop();
        }

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[i] < heights[st.top()]) st.pop();

            if (st.empty()) nextSmaller[i] = n;
            else nextSmaller[i] = st.top();

            st.push(i);
        }

        int maxi = 0;

        for (int i = 0; i < n; i++) {
            int curr = (nextSmaller[i] - prevSmaller[i] - 1) * heights[i];
            maxi = max(curr, maxi);
        }

        return maxi;
    }
};