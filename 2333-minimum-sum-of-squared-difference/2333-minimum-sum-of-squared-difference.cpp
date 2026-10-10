class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        // int n = nums1.size();
        // priority_queue<int> pq;
        // long long k = 1LL * k1 + k2;

        // for (int i = 0; i < n; i++) {
        //     pq.push(abs(nums1[i] - nums2[i]));
        // }

        // while (k > 0 && pq.top() > 0) {
        //     int top = pq.top();
        //     pq.pop();

        //     pq.push(top - 1);
        //     k--;
        // }

        // long long ans = 0;
        // while (!pq.empty()) {
        //     ans += pq.top() * pq.top();
        //     pq.pop();
        // }

        // return ans;

        // int n = nums1.size();
        // long long k = 1LL * k1 + k2;

        // vector<int> diff(n);
        // long long total = 0;

        // for (int i = 0; i < n; i++) {
        //     diff[i] = abs(nums1[i] - nums2[i]);
        //     total += diff[i];
        // }

        // if (total <= k) return 0;

        // sort(diff.begin(), diff.end(), greater<int>());

        // diff.push_back(0);

        // for (int i = 0; i < n; i++) {
        //     long long cost = 1LL * (diff[i] - diff[i + 1]) * (i + 1);

        //     if (cost <= k) {
        //         k -= cost;
        //     }
        //     else {
        //         int level = diff[i] - k/(i+1);
        //         long long rem = k % (i + 1);
        //         long long ans = 0;

        //         for (int j = 0; j <= i; j++) {
        //             ans += 1LL * level * level;
        //         }

        //         ans -= rem * (2LL * level - 1);

        //         for (int j = i + 1; j < n; j++) {
        //             ans += 1LL * diff[j] * diff[j];
        //         }

        //         return ans;
        //     }
        // }

        int n = nums1.size();
        long long k = 1LL * k1 + k2;
        int mx = 0;
        long long total = 0;
        vector<int> freq(100001, 0);

        for (int i = 0; i < n; i++) {
            int diff = abs(nums1[i] - nums2[i]);
            mx = max(mx, diff);
            freq[diff]++;
            total += diff;
        }

        if (total <= k) return 0;

        for (int d = mx; d > 0 && k > 0; d--) {
            long long cnt = freq[d];
            if (cnt == 0) continue;

            long long take = min(k, cnt);
            freq[d] -= take;
            freq[d - 1] += take;
            k -= take;
        }

        long long ans = 0;

        for (int d = 1; d <= mx; d++) {
            ans += 1LL * d * d * freq[d];
        }

        return ans;
    }
};