/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void recr(vector<tuple<int, int, int>>& list, TreeNode* root, int r, int c) {
        if (root == nullptr) return;
        list.emplace_back(c, r, root->val);
        recr(list, root->left, r + 1, c - 1);
        recr(list, root->right, r + 1, c + 1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<tuple<int, int, int>> list;
        recr(list, root, 0, 0);

        sort(list.begin(), list.end());

        vector<vector<int>> ans;
        int prev = INT_MIN;

        for (auto& [col, row, val] : list) {
            if (col != prev) {
                ans.push_back({});
                prev = col;
            }
            ans.back().push_back(val);
        }

        return ans;
    }
};