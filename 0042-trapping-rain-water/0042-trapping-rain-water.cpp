class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n <= 2) return 0;

        int water = 0;

        vector<int> prefix(n);
        prefix[0] = height[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = max(prefix[i - 1], height[i]);
        }

        vector<int> suffix(n);
        suffix[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = max(suffix[i + 1], height[i]);
        }

        for (int i = 1; i < n - 1; i++) {
            if (prefix[i - 1] > height[i] && suffix[i + 1] > height[i]) {
                water += min(prefix[i - 1], suffix[i + 1]) - height[i];
            }
        }

        return water;
    }
};