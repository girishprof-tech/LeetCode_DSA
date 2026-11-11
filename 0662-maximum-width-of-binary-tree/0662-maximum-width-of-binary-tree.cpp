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
        if (root == nullptr) return 0;

        int ans = 1;
        queue<pair<TreeNode*, long long>> q;

        q.push({root, 1});

        while (!q.empty()) {
            int first = 0, last = 0;
            int size = q.size();

            for (int i = 0; i < size; i++) {
                TreeNode* curr = q.front().first;
                long long num = q.front().second;
                q.pop();

                if (first == 0) first = num;
                last = num;

                if (curr->left) q.push({curr->left, num * 2 - (first - 1) * 2 - 1});
                if (curr->right) q.push({curr->right, num * 2 - (first - 1) * 2});
            }

            ans = max(ans, last - first + 1);
        }

        return ans;
    }
};