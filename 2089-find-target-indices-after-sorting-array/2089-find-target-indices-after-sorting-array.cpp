class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int n = nums.size();
        int freq = 0, smallCnt = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] == target) freq++;
            else if (nums[i] < target) smallCnt++;
        }

        vector<int> ans;
        ans.reserve(freq);
        
        for (int i = 0; i < freq; i++) {
            ans.push_back(smallCnt);
            smallCnt++;
        }

        return ans;
    }
};