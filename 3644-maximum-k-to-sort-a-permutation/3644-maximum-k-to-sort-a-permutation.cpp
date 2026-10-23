class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();
        int mx = -1;
        
        for (int i = 0; i < n; i++) {
            if (nums[i] != i) mx &= nums[i];
        }

        return max(mx, 0);
    }
};