class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n <= 2) return 0;

        int water = 0, lMax = 0, rMax = 0;
        int l = 0, r = n - 1;

        while (l < r) {
            if (height[l] <= height[r]) {
                if (lMax > height[l]) {
                    water += min(lMax, height[r]) - height[l];
                }
                lMax = max(lMax, height[l]);
                l++;
            }
            else {
                if (rMax > height[r]) {
                    water += min(height[l], rMax) - height[r];
                }

                rMax = max(rMax, height[r]);
                r--;
            }
        }

        return water;
    }
};