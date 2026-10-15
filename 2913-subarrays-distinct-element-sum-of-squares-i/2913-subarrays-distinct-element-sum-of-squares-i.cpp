class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        vector<int> freq(101);

        for (int i = 0; i < n; i++) {
            int cnt = 0;

            for (int j = i; j < n; j++) {
                cnt += (freq[nums[j]] != i + 1);
                freq[nums[j]] = i + 1;
                ans += (cnt * cnt);
            }
        }

        return ans;
    }
};