class Solution {
public:
    int between(vector<int>& height, int i, int j) {
        int mx = 0;
        for (int t = i + 1; t < j; t++) {
            mx = max(mx, height[t]);
        }
        return mx;
    }
    int trap(vector<int>& height) {
        int n = height.size();
        if (n <= 2) return 0;

        int cnt = 0;
        stack<pair<int, int>> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && st.top().first <= height[i]) {
                int diff = between(height, st.top().second, i);

                cnt += (i - st.top().second - 1) * (st.top().first - diff);

                st.pop();
            }
            
            if (!st.empty()) {
                int diff2 = between(height, st.top().second, i);
                cnt += (i - st.top().second - 1) * (height[i] - diff2);
            }

            st.push({height[i], i});
        }

        return cnt;
    }
};