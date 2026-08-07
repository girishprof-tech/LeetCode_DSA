class Solution {
public:
    void func(vector<vector<int>> &ans, vector<int> &nums, vector<int> temp, int i) {
        if (i == nums.size()) {
            ans.push_back(temp);
            return;
        }

        temp.push_back(nums[i]);
        func(ans, nums, temp, i + 1);
        temp.pop_back();
        func(ans, nums, temp, i + 1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        func(ans, nums, temp, 0);
        return ans;
    }
};