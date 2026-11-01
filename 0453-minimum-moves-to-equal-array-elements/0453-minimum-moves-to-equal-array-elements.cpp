class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;

        sort(nums.begin(), nums.end());
        int res = 0;
        
        int dec = 1, ind = n - 2;
        while (ind >= 0) {
            res += dec * (nums[ind + 1] - nums[ind]);
            dec++;
            ind--;
        }

        return res;
    }
};