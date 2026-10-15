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

        int left = add(root->left);
        int right = add(root->right);

        sum = max(sum, root->val + max(max(left + right, 0), max(left, right)));

        return max(root->val + max(left, right), 0);
    }
    int maxPathSum(TreeNode* root) {
        if (root == nullptr) return 0;
        add(root);
        return sum;
    }
};