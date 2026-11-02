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
    void recr(TreeNode* root, map<int, int>& mpp, int r) {
        if (root == nullptr) return;

        mpp[r] = root->val;

        recr(root->left, mpp, r + 1);
        recr(root->right, mpp, r + 1);
    }
    vector<int> rightSideView(TreeNode* root) {
        map<int, int> mpp;
        recr(root, mpp, 0);

        vector<int> ans;
        for (auto it : mpp) {
            ans.push_back(it.second);
        }

        return ans;
    }
};