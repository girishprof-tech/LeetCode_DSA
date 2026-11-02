/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void recr(TreeNode* root, vector<int>& ans, int row) {
        if (!root) return;

        if (ans.size() == row) {
            ans.push_back(root->val);
        }

        recr(root->right, ans, row + 1);
        recr(root->left, ans, row + 1);
    }
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) return {};
        vector<int> ans;
        recr(root, ans, 0);
        return ans;
    }
};