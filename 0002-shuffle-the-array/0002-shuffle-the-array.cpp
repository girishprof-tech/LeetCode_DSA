class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans(2 * n);
        int left = 0, right = n;
        
        for (int i = 0; i < 2 * n; i += 2) {
            ans[i] = nums[left++];
            ans[i + 1] = nums[right++];
        }

        return ans;
    }
};