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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;
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

        vector<int> ans;
        unordered_map<TreeNode*, bool> visited;
        while (!q.empty()) q.pop();
        q.push(target);

        while (!q.empty()) {
            int n = q.size();
            if (k == 0) break;

            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();

                visited[node] = true;
                
                if (node->left && !visited[node->left]) {
                    q.push(node->left);
                }
                if (node->right && !visited[node->right]) {
                    q.push(node->right);
                }
                if (node != root && !visited[parent[node]]) {
                    q.push(parent[node]);
                }
            }

            k--;
        }

        while (!q.empty()) {
            ans.push_back(q.front()->val);
            q.pop();
        }

        return ans;
    }
};