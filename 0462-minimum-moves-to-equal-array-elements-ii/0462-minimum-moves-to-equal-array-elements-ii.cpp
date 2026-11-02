class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        sort(nums.begin(), nums.end());

        int med = nums[(n - 1) / 2];

        for (int i = 0; i < n; i++) {
            res += abs(nums[i] - med);
        }

        return res;
    }
};