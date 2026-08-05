class Solution {
public:
    void func(vector<vector<int>> &ans, vector<int>& candidates, vector<int>& temp, int ind, int sum) {
        if (sum == 0 && !temp.empty()) {
            ans.push_back(temp);
            return;
        }
        
        if (ind >= candidates.size() || sum < 0) return;
        
        temp.push_back(candidates[ind]);
        func(ans, candidates, temp, ind, sum - candidates[ind]);
        temp.pop_back();
        func(ans, candidates, temp, ind + 1, sum);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        func(ans, candidates, temp, 0, target);
        return ans;
    }
};