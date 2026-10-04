class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n - k + 1);
        deque<int> dq;
        
        for (int i = 0; i < n; i++) {
            while (!dq.empty() && nums[dq.back()] <= nums[i]) dq.pop_back();
            dq.push_back(i);

            if (dq.back() - dq.front() >= k) dq.pop_front();

            if (i >= k - 1) ans[i - k + 1] = nums[dq.front()];
        }

        return ans;
    }
};