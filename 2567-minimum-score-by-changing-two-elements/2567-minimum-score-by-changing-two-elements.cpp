class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int l1 = INT_MAX, l2 = INT_MAX, l3 = INT_MAX;
        int h1 = INT_MIN, h2 = INT_MIN, h3 = INT_MIN;

        for (int i = 0; i < nums.size(); i++) {
            if (l1 >= nums[i]) l3 = l2, l2 = l1, l1 = nums[i];
            else if (l2 >= nums[i]) l3 = l2, l2 = nums[i];
            else if (l3 > nums[i]) l3 = nums[i];

            if (h1 <= nums[i]) h3 = h2, h2 = h1, h1 = nums[i];
            else if (h2 <= nums[i]) h3 = h2, h2 = nums[i];
            else if (h3 < nums[i]) h3 = nums[i];
        }

        return min(h3 - l1, min(h1 - l3, h2 - l2));
    }
};