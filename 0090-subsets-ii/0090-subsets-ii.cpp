class Solution {
public:
    void func(set<vector<int>> &ans, vector<int> &nums, vector<int> temp, int ind) {
        if (ind == nums.size()) {
            sort(temp.begin(), temp.end());
            ans.insert(temp);
            return;
        }

        temp.push_back(nums[ind]);
        func(ans, nums, temp, ind + 1);
        temp.pop_back();
        func(ans, nums, temp, ind + 1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> ans;
        vector<int> temp;
        func(ans, nums, temp, 0);

        vector<vector<int>> res(ans.begin(), ans.end());
        return res;
    }
};