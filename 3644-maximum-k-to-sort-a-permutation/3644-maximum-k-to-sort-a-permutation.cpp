class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();
        int mx = 0;
        int i = 0;

        while (i < n) {
            if (nums[i] != i) {
                mx = nums[i];
                break;
            }
            i++;
        }

        while (i < n) {
            if (nums[i] != i) {
                mx &= nums[i];
            }
            i++;
        }

        return mx;
    }
};