class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n / 2; i++) {
            res += nums[n / 2] - nums[i];
        }
        for (int i = n / 2 + 1; i < n; i++) {
            res += nums[i] - nums[n / 2];
        }

        return res;
    }
};