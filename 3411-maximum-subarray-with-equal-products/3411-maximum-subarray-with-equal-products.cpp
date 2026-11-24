class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;

        for (int i = 0; i < n; i++) {
            long long prod = nums[i];
            int lcm = nums[i], gcd = nums[i];

            for (int j = i + 1; j < n; j++) {
                prod *= nums[j];
                if (prod > 100000000000) break;
                
                int cnt = 1;
                while (lcm * cnt % nums[j] != 0)
                    cnt++;

                lcm = lcm * cnt;
                gcd = max(gcd * nums[j] / lcm, 1);

                if (prod == lcm * gcd)
                    ans = max(ans, j - i + 1);
            }
        }

        return ans;
    }
};