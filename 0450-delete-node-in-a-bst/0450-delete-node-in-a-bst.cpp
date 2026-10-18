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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr || (root->left == nullptr && root->right == nullptr && key == root->val))
            return nullptr;

        TreeNode* curr = root;
        TreeNode* prev = curr;
        while (curr && curr->val != key) {
            if (curr->val > key) {
                prev = curr;
                curr = curr->left;
            }
            else {
                prev = curr;
                curr = curr->right;
            }
        }
        
        if (curr == nullptr) return root;

        if (!curr->right && !curr->left) {
            if (prev->val > key) {
                prev->left = nullptr;
            }
            else {
                prev->right = nullptr;
            }

            delete curr;
            return root;
        }

        if (!curr->right) {
            if (curr == root) {
                root = root->left;
            }
            if (prev->val > key) {
                prev->left = curr->left;
            }
            else {
                prev->right = curr->left;
            }
            delete curr;
            return root;
        }
        else if (!curr->left) {
            if (curr == root) {
                root = root->right;
            }

            if (prev->val > key) {
                prev->left = curr->right;
            }
            else {
                prev->right = curr->right;
            }

            delete curr;
            return root;
        }

        prev = curr;
        TreeNode* temp = curr->left;

        while (temp->right) {
            prev = temp;
            temp = temp->right;
        }
        curr->val = temp->val;

        if (!temp->right && !temp->left) {
            if (curr->left == temp) prev->left = nullptr;
            else prev->right = nullptr;
        }
        else {
            if (curr->left == temp) prev->left = temp->left;
            else prev->right = temp->left;
        }
        
        delete temp;
        return root;
    }
};