class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        int mx = 0;
        int cand = 0, cMax = 0;

        for (int i = 0; i < n; i++) {
            mx = max(mx, nums[i]);

            if (cand == i) cMax = mx;

            if (nums[i] < cMax - k) {
                cand = i + 1;
            }
        }

        return cand < n ? cand : -1;
    }
};