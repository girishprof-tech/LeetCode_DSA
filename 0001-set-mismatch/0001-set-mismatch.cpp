class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> freq(n + 1, 0);

        int og = n * (n + 1) / 2;
        int sum = 0;
        for (int num : nums) {
            sum += num;
            freq[num]++;
        }

        int twice = 0;

        for (int i = 0; i < n + 1; i++) {
            if (freq[i] == 2) {
                twice = i;
                break;
            }
        }

        int missing = twice + og - sum;
        return {twice, missing};
    }
};