class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        int n = beans.size();
        long long res = LLONG_MAX;
        sort(beans.begin(), beans.end());

        long long sum = accumulate(beans.begin(), beans.end(), 0LL);

        for (int i = 0; i < n; i++) {
            long long temp = sum - 1LL * (n - i) * beans[i];
            res = min(res, temp);
        }

        return res;
    }
};