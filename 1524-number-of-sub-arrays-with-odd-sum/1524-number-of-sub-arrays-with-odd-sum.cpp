class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        const int MOD = 1e9 + 7;
        int even = 1, odd = 0;

        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
            
            if (sum % 2 == 1) odd++;
            else even++;
        }

        return 1LL * odd * even % MOD;
    }
};