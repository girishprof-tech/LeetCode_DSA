class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total < x) return -1;
        if (total == x) return n;

        int l = 0;
        int sum = 0;
        int mx = 0;
        for (int r = 0; r < n; r++) {
            sum += nums[r];

            while (sum > total - x) {
                sum -= nums[l];
                l++;
            }

            if (sum == total - x) {
                mx = max(mx, r - l + 1);
            }
        }

        if (mx == 0) return -1;

        return n - mx;
    }
};