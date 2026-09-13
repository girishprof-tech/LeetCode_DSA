class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans(2 * n);
        int left = 0, right = n;
        int i = 0;

        while (left < n && right < 2 * n) {
            ans[i] = nums[left];
            ans[i + 1] = nums[right];

            left++;
            right++;
            i += 2;
        }

        return ans;
    }
};