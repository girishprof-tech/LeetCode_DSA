class Solution {
public:
    const int MOD = 1e9 + 7;
    long long binary_exponentiation(long long x, long long n) {
        if (x == 1 || n == 0) return 1;

        long long ans = 1;
        while (n > 0) {

            if (n % 2 != 0) {
                ans = (ans * x) % MOD;
            }

            x = (x * x) % MOD;
            n = n / 2;
        }

        return ans;
    }
    int countGoodNumbers(long long n) {
        long long even = (n + 1) / 2;
        long long odd = n / 2;

        return (binary_exponentiation(5, even) * binary_exponentiation(4, odd)) % MOD;
    }
};