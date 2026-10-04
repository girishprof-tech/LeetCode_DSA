class Solution {
public:
    void maxArea(vector<int>& heights, int& maxi) {
        int n = heights.size();
        stack<int> st;
        
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                int top = st.top();
                st.pop();

                int pse = st.empty() ? -1 : st.top();
                maxi = max(maxi, (i - pse - 1) * heights[top]);
            }

            st.push(i);
        }

        while (!st.empty()) {
            int top = st.top();
            st.pop();
            int pse = st.empty() ? -1 : st.top();
            maxi = max(maxi, (n - pse - 1) * heights[top]);
        }
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> heights(n, 0);
        int maxi = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '0') {
                    heights[j] = 0;
                }
                else {
                    heights[j] += 1;
                }
            }

            maxArea(heights, maxi);
        }

        return maxi;
    }
};