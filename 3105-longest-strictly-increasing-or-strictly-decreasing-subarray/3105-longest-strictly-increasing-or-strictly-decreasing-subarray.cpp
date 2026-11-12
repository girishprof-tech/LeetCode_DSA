class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int max1 = 0, max2 = 0;

        int cnt1 = 1, cnt2 = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                cnt1++;
                max2 = max(cnt2, max2);
                cnt2 = 1;
            }
            else if (nums[i] < nums[i - 1]) {
                cnt2++;
                max1 = max(max1, cnt1);
                cnt1 = 1;
            }
            else {
                max1 = max(max1, cnt1);
                max2 = max(max2, cnt2);
                cnt1 = 1, cnt2 = 1;
            }
        }

        max1 = max(cnt1, max1);
        max2 = max(cnt2, max2);

        return max(max1, max2);
    }
};