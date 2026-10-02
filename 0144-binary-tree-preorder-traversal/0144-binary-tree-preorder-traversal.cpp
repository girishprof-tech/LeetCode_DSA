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
    void recr(vector<int>& ans, TreeNode* root) {
        if (root == nullptr) return;

        ans.push_back(root->val);
        if (root->left != nullptr) recr(ans, root->left);
        if (root->right != nullptr) recr(ans, root->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;

        recr(ans, root);

        return ans;
    }
};