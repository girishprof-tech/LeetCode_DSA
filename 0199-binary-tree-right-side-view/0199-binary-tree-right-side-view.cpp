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
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) return {};
        queue<pair<TreeNode*, int>> q;
        vector<int> ans;
        
        q.push({root, 0});

        while (!q.empty()) {
            int n = q.size();

            for (int i = 0; i < n; i++) {
                TreeNode* curr = q.front().first;
                int row = q.front().second;
                q.pop();

                if (i == n - 1) ans.push_back(curr->val);

                if (curr->left) q.push({curr->left, row + 1});
                if (curr->right) q.push({curr->right, row + 1});
            }
        }

        return ans;
    }
};