class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;

        for (int i = 0; i < n; i++) {
            unsigned long long prod = nums[i];
            int lcm = nums[i], gcd = nums[i];

            for (int j = i + 1; j < n; j++) {
                long long cnt = 1;

                while (lcm * cnt % nums[j] != 0)
                    cnt++;

                lcm = lcm * cnt;
                gcd = max(gcd * nums[j] / lcm, 1);
                prod *= nums[j];

                if (prod == lcm * gcd)
                    ans = max(ans, j - i + 1);
            }
        }

        return ans;
    }
};