class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int high1 = nums[n - 1] - nums[2];
        int high2 = nums[n - 3] - nums[0];
        int high3 = nums[n - 2] - nums[1];

        return min(high1, min(high2, high3));
    }
};