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
    int sum = INT_MIN;
    int add(TreeNode* root) {
        if (root == nullptr) return 0;

        int left = max(0, add(root->left));
        int right = max(0, add(root->right));

        sum = max(sum, root->val + left + right);
        return root->val + max(left, right);
    }
    int maxPathSum(TreeNode* root) {
        if (root == nullptr) return 0;
        add(root);
        return sum;
    }
};