class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> freq(n + 1, 0);

        for (int num : nums) freq[num]++;

        int twice = -1;
        int missing = -1;

        for (int i = 1; i < n + 1; i++) {
            if (freq[i] == 2) twice = i;
            if (freq[i] == 0) missing = i;
        }

        return {twice, missing};
    }
};