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
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        int ans = 1;
        queue<pair<TreeNode*, long long>> q;

        q.push({root, 1});

        while (!q.empty()) {
            long long first = q.front().second;
            long long last = q.back().second;
            int size = q.size();

            ans = max(ans, int(last - first + 1));

            for (int i = 0; i < size; i++) {
                TreeNode* curr = q.front().first;
                long long num = q.front().second;
                q.pop();

                if (curr->left) {
                    q.push({curr->left, num * 2 - first - 1});
                }
                if (curr->right) {
                    q.push({curr->right, num * 2 - first});
                }
            }
        }

        return ans;
    }
};