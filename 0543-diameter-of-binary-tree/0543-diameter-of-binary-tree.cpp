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
    stack<int> st;
    int depth(TreeNode* root) {
        if (root == nullptr) return 0;

        int left = depth(root->left);
        int right = depth(root->right);

        if (st.empty()) {
            st.push(left + right);
        }
        else if (st.top() < left + right) {
            st.pop();
            st.push(left + right);
        }

        return 1 + max(left, right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr) return 0;

        int d = depth(root);

        return st.top();
    }
};