/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode*, pair<int, int>>> q;
        map<int, map<int, multiset<int>>> mpp;
        q.push({root, {0, 0}});

        while (!q.empty()) {
            int n = q.size();

            for (int i = 0; i < n; i++) {
                TreeNode* curr = q.front().first;
                int x = q.front().second.first, y = q.front().second.second;
                q.pop();

                mpp[x][y].insert(curr->val);

                if (curr->left) q.push({curr->left, {x - 1, y + 1}});
                if (curr->right) q.push({curr->right, {x + 1, y + 1}});
            }
        }

        vector<vector<int>> ans;

        for (auto p : mpp) {
            vector<int> temp;
            for (auto i : p.second) {
                temp.insert(temp.end(), i.second.begin(), i.second.end());
            }
            ans.push_back(temp);
        }

        return ans;
    }
};