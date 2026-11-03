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
    unordered_set<int> st;
    bool found = false;
    void recr(TreeNode* root, TreeNode*& p) {
        if (!root || found) return;

        if (root->val == p->val) {
            st.insert(root->val);
            found = true;
            return;
        }

        if (!found) recr(root->left, p);
        if (!found) recr(root->right, p);
        
        if (found) st.insert(root->val);
    }
    void recr2(TreeNode* root, TreeNode*& q, TreeNode*& ans) {
        if (!root || found) return;

        if (root->val == q->val) {
            found = true;
        }

        if (!found) recr2(root->left, q, ans);
        if (!found) recr2(root->right, q, ans);

        if (!ans && found && st.count(root->val)) {
            ans = root;
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        recr(root, p);
        found = false;
        
        for (auto it : st) {
            cout << it << " ";
        }

        TreeNode* ans = nullptr;
        recr2(root, q, ans);

        return ans;
    }
};