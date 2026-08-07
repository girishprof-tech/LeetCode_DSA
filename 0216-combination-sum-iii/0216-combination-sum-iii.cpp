class Solution {
public:
    void func(vector<vector<int>> &ans, int num, vector<int>& temp, int n, int k) {
        if (temp.size() == k) {
            if (n == 0) {
                ans.push_back(temp);
            }
            return;
        }

        if (num <= n && num <= 9) {
            temp.push_back(num);
            func(ans, num + 1, temp, n - num, k);
            temp.pop_back();
            func(ans, num + 1, temp, n, k);
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        func(ans, 1, temp, n, k);
        return ans;
    }
};