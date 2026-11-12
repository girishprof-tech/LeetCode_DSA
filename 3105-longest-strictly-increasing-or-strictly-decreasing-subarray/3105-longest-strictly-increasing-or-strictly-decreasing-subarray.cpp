class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        int cnt1 = 1, cnt2 = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                cnt1++;
                cnt2 = 1;
            }
            else if (nums[i] < nums[i - 1]) {
                cnt2++;
                cnt1 = 1;
            }
            else {
                cnt1 = 1;
                cnt2 = 1;
            }
            ans = max(ans, max(cnt1, cnt2));
        }

        ans = max(ans, max(cnt1, cnt2));

        return ans;
    }
};