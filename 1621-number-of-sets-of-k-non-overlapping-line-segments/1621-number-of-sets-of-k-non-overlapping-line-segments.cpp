class Solution {
public:
    const int MOD = 1e9 + 7;
    long long power(long long n, long long r) {
        long long ans = 1;
        while (r) {
            if (r & 1) ans = ans * n % MOD;
            n = n * n % MOD;
            r >>= 1;
        }
        return ans;
    }
    int numberOfSets(int n, int k) {
        int N = n + k - 1;
        int R = 2 * k;

        vector<long long> fact(N + 1);
        fact[0] = 1;

        for (int i = 1; i <= N; i++) {
            fact[i] = (fact[i - 1] * i) % MOD;
        }

        vector<long long> invFact(N + 1);
        invFact[N] = power(fact[N], MOD - 2);

        for (int i = N; i >= 1; i--) {
            invFact[i - 1] = invFact[i] * i % MOD;
        }

        return fact[N] * invFact[R] % MOD * invFact[N - R] % MOD;
    }
};