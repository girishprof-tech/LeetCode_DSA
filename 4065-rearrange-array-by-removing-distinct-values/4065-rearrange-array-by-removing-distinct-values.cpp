class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        vector<int> freq(101, 0);

        for (int i = 0; i < n; i++) {
            freq[nums[i]]++;
        }

        while (n > 0) {
            for (int i = 0; i < 101; i++) {
                if (freq[i] != 0) {
                    ans.push_back(i);
                    freq[i]--;
                    n--;
                }
            }
        }
        
        return ans;
    }
};