class Solution {
public:
    void func(vector<vector<int>> &ans, vector<int> &nums, vector<int> &temp, int ind) {
        ans.push_back(temp);
        
        for (int i = ind; i < nums.size(); i++) {
            if (i > ind && nums[i] == nums[i - 1]) continue;

            temp.push_back(nums[i]);
            func(ans, nums, temp, i + 1);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;

        sort(nums.begin(), nums.end());

        func(ans, nums, temp, 0);
        return ans;
    }
};