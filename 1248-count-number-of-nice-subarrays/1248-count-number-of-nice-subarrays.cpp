class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;

        vector<int> hash;

        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 == 1) hash.push_back(i);
        }

        int cnt = hash.size();
        if (cnt == 0 || k > cnt) return 0;

        for (int i = 0; i < cnt - k + 1; i++) {
            int left = (i == 0) ? -1 : hash[i - 1];
            int right = (i + k == cnt) ? n : hash[i + k];

            int l = hash[i] - left;
            int r = right - hash[i + k - 1];

            ans += (l * r);
        }

        return ans;
    }
};