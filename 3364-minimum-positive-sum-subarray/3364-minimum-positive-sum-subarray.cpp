class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int ans = INT_MAX;

        for (int i = l - 1; i < r; i++) {
            int left = 0, right = left + i;
            int sum = 0;

            for (int j = left; j < right; j++) {
                sum += nums[j];
            }

            while (right < n) {
                sum += nums[right];

                if (sum > 0 && sum < ans) {
                    ans = sum;
                }

                right++;
                sum -= nums[left];
                left++;
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};