class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int best = 1, keep = 1, bump = 1, last = -10;

        for (int x : nums) {
            if (x - last == 0) {
                bump = keep + 1;
            }
            else if (x - last == 1) {
                ++keep, ++bump;
            }
            else if (x - last == 2) {
                keep = bump + 1, bump = 1;
            }
            else keep = bump = 1;

            best = max({best, keep, bump});
            last = x;
        }

        return best;
    }
};