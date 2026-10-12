class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const long long MOD = 1e9 + 7;
        vector<int> cnt(32, 0);

        for (int num : nums) {
            for (int i = 0; i < 32; i++) {
                if (num & (1LL << i))
                    cnt[i]++;
            }
        }

        long long ans = 0;

        for (int i = 0; i < k; i++) {
            long long curr = 0;

            for (int b = 0; b < 32; b++) {
                if (cnt[b] > 0) {
                    curr |= (1LL << b);
                    cnt[b]--;
                }
            }

            ans = (ans + curr * curr) % MOD;
        }

        return ans;
    }
};