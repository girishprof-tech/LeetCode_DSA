class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        vector<int> countPerNum(101, 0);

        for (int i = 0; i < n; i++) countPerNum[nums[i]]++;

        int currCount = 0;
        for (int i = 0; i < 101; i++) {
            int temp = countPerNum[i];
            countPerNum[i] = currCount;
            currCount += temp;
        }

        for (int i = 0; i < n; i++) {
            ans[i] = countPerNum[nums[i]];
        }

        return ans;
    }
};