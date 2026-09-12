class Solution {
public:
    int between(vector<int>& height, int i, int j) {
        int mx = 0;
        for (int r = i + 1; r < j; r++) {
            mx = max(height[r], mx);
        }

        return mx;
    }
    int trap(vector<int>& height) {
        int n = height.size();
        if (n <= 2) return 0;
        int water = 0;
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && height[st.top()] <= height[i]) {
                int diff = between(height, st.top(), i);
                water += (i - st.top() - 1) * (height[st.top()] - diff);
                st.pop();
            }

            if (!st.empty()) {
                int diff = between(height, st.top(), i);
                water += (i - st.top() - 1) * (height[i] - diff);
            }

            st.push(i);
        }

        return water;
    }
};