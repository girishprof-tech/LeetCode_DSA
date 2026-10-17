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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr) return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);

        int level = 0;
        while (!q.empty()) {
            int n = q.size();
            vector<int> temp;

            for (int i = 0; i < n; i++) {
                TreeNode* top = q.front();
                q.pop();
                temp.push_back(top->val);

                if (top->left) q.push(top->left);
                if (top->right) q.push(top->right);
            }

            if (level % 2) reverse(temp.begin(), temp.end());
            ans.push_back(temp);
            level++;
        }

        return ans;
    }
};