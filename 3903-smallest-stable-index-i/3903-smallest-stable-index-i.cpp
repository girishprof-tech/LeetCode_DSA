class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        int mx = 0;
        int mn = INT_MAX;

        for (int i = 0; i < n; i++) {
            mn = min(mn, nums[i]);
        }

        for (int i = 0; i < n; i++) {
            mx = max(mx, nums[i]);

            if (i != 0 && nums[i - 1] == mn) {
                mn = INT_MAX;
                for (int j = i; j < n; j++) {
                    mn = min(mn, nums[j]);
                }
            }

            if (mx - mn <= k) return i;
        }

        return -1;
    }
};