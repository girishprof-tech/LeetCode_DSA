class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size(), n = nums2.size();

        int i = 0, j = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for (int i = 0; i < m; i++) {
            pq.push({nums1[i] + nums2[0], 0});
        }

        vector<vector<int>> ans;
        while (k-- && !pq.empty()) {
            int sum = pq.top().first;
            int i = pq.top().second;
            pq.pop();

            ans.push_back({sum - nums2[i], nums2[i]});
            
            if (i + 1 < n) {
                pq.push({sum - nums2[i] + nums2[i + 1], i + 1});
            }
        }

        return ans;
    }
};