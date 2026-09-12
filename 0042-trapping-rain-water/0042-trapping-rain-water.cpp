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
                    water += lMax - height[l];
                }
                else lMax = height[l];
                l++;
            }
            else {
                if (rMax > height[r]) {
                    water += rMax - height[r];
                }
                else rMax = height[r];
                r--;
            }
        }

        return water;
    }
};