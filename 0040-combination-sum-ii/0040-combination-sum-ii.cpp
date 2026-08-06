class Solution {
public:
    void func(vector<vector<int>> &ans, vector<int> &candidates, vector<int> &temp, int ind, int target) {
        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        for (int i = ind; i < candidates.size(); i++) {
            if (i > ind && candidates[i] == candidates[i - 1]) continue;

            if (candidates[i] > target) break;

            temp.push_back(candidates[i]);
            func(ans, candidates, temp, i + 1, target - candidates[i]);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        func(ans, candidates, temp, 0, target);
        return ans;
    }
};