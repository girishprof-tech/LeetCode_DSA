class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        
        unordered_map<int, int> mpp;
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());
        mpp[temp[0]] = 0;

        for (int i = 1; i < n; i++) {
            while (i < n && temp[i] == temp[i - 1]) i++;
            
            if (i >= n) break;
            mpp[temp[i]] = i;
        }

        for (int i = 0; i < n; i++) {
            ans[i] = mpp[nums[i]];
        }

        return ans;
    }
};