/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void dfs(vector<int>& ans, unordered_set<int>& visited, unordered_map<TreeNode*, TreeNode*>& parent, TreeNode* root, int lvl, int k) {
        if (root == nullptr) return;

        if (lvl == k) {
            ans.push_back(root->val);
            return;
        }

        visited.insert(root->val);

        if (root->left && visited.find(root->left->val) == visited.end()) dfs(ans, visited, parent, root->left, lvl + 1, k);
        if (root->right && visited.find(root->right->val) == visited.end()) dfs(ans, visited, parent, root->right, lvl + 1, k);
        if (parent[root] && visited.find(parent[root]->val) == visited.end()) dfs(ans, visited, parent, parent[root], lvl + 1, k);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;
        vector<int> ans;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                if (node->left) {
                    parent[node->left] = node;
                    q.push(node->left);
                }

                if (node->right) {
                    parent[node->right] = node;
                    q.push(node->right);
                }
            }
        }

        unordered_set<int> visited;
        visited.insert(target->val);
        dfs(ans, visited, parent, target, 0, k);
        return ans;
    }
};