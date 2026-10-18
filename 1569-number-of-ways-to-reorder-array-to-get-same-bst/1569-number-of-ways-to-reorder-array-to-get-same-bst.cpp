class Solution {
public:
    static const int MOD = 1e9 + 7;
    vector<long long> fact, invFact;

    long long power(long long a, long long b) {
        long long ans = 1;

        while (b > 0) {
            if (b & 1) {
                ans = ans * a % MOD;
            }

            a = a * a % MOD;
            b >>= 1;
        }

        return ans;
    }

    void build(int n) {
        fact.resize(n + 1);
        invFact.resize(n + 1);

        fact[0] = 1;
        for (int i = 1; i <= n; i++) {
            fact[i] = fact[i - 1] * i % MOD;
        }

        invFact[n] = power(fact[n], MOD - 2);

        for (int i = n; i >= 1; i--) {
            invFact[i - 1] = invFact[i] * i % MOD;
        }
    }

    long long nCr(int n, int r) {
        if (r < 0 || r > n)
            return 0;

        return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
    }

    long long helper(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2)
            return 1;

        vector<int> left, right;
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[0])
                right.push_back(nums[i]);
            else
                left.push_back(nums[i]);
        }

        int l = left.size();

        return nCr(n - 1, l) * helper(left) % MOD * helper(right) % MOD;
    }

    int numOfWays(vector<int>& nums) {
        build(nums.size());
        return (helper(nums) - 1 + MOD) % MOD;
    }
};