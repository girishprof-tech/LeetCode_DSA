class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        int n = beans.size();
        long long res = LLONG_MAX;
        sort(beans.begin(), beans.end());

        long long sum = 0;
        for (int i = 0; i < n; i++) sum += beans[i];

        for (int i = 0; i < n; i++) {
            long long temp = sum - 1LL * (n - i) * beans[i];
            res = min(res, temp);
        }

        return res;
    }
};