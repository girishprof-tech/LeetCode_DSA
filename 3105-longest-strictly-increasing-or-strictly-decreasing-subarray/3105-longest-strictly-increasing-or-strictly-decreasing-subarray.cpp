class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int max1 = 0;
        int max2 = 0;

        int cnt = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) cnt++;
            else {
                max1 = max(max1, cnt);
                cnt = 1;
            }
        }

        max1 = max(cnt, max1);
        cnt = 1;

        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[i - 1]) cnt++;
            else {
                max2 = max(max2, cnt);
                cnt = 1;
            }
        }
        
        max2 = max(max2, cnt);

        return max(max1, max2);
    }
};