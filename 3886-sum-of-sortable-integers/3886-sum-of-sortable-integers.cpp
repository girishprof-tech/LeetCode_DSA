class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        int res = 0;

        int edge = 0;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] > nums[i + 1]) edge++;
        }
        if (edge == 0) res += 1;

        for (int k = 2; k <= n; k++) {
            if (n % k != 0) continue;
            
            int prevMax = INT_MIN;
            bool flag = true;
            for (int i = 0; i < n; i += k) {
                int currMax = INT_MIN;
                int currMin = INT_MAX;
                int cnt = 0;

                for (int j = 0; j < k; j++) {
                    if (nums[i + j] > nums[i + (j + 1) % k]) cnt++;

                    currMin = min(currMin, nums[i + j]);
                    currMax = max(currMax, nums[i + j]);
                }

                if (prevMax > currMin || cnt > 1) {
                    flag = false;
                    break;
                }

                prevMax = currMax;
            }

            if (flag) res += k;
        }


        return res;
    }
};