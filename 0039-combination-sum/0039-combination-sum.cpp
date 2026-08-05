class Solution {
public:
    void func(vector<vector<int>> &ans, vector<int>& candidates, vector<int>& temp, int ind, int sum) {
        if (ind >= candidates.size()) {
            if (sum == 0) {
                ans.push_back(temp);
            }
            return;
        }
        
        if (candidates[ind] <= sum) {
            temp.push_back(candidates[ind]);
            func(ans, candidates, temp, ind, sum - candidates[ind]);
            temp.pop_back();
        }

        func(ans, candidates, temp, ind + 1, sum);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        func(ans, candidates, temp, 0, target);
        return ans;
    }
};