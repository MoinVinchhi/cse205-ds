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
    bool solve ( TreeNode* l, TreeNode* r) {

        if (l==NULL && r==NULL) {
            return true;
        }

        if (l==NULL || r==NULL) {
            return false;
        }

        bool left = solve (l->left, r->right);
        bool right = solve (l->right, r->left);
        bool value = l->val==r->val;

        return left && right && value;
    }

    bool isSymmetric(TreeNode* root) {
        
        return solve (root->left, root->right);
    }
};