class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        if (nums[0] > x && nums[n - 1] > x) return -1;
        if (nums[0] == x || nums[n - 1] == x) return 1;

        int total = accumulate(nums.begin(), nums.end(), 0);

        if (total < x) return -1;

        vector<pair<int, int>> subarrays;
        int req = total - x;
        int l = 0;

        long long sum = 0;
        for (int r = 0; r < n; r++) {
            sum += nums[r];

            while (sum > req) {
                sum -= nums[l];
                l++;
            }

            if (sum == req) {
                subarrays.push_back({l, r});
            }
        }
        
        int m = subarrays.size();
        if (m == 0) return -1;

        int mx = 0;
        for (int i = 0; i < m; i++) {
            mx = max(mx, subarrays[i].second - subarrays[i].first + 1);
        }

        return n - mx;
    }
};