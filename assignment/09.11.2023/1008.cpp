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
    TreeNode* solve (vector<int> vec, int mini, int maxi, int &i) {

        if (i>=vec.size()) {
            return NULL;
        }

        if (vec[i]<mini || vec[i]>maxi) {
            return NULL;
        }

        TreeNode* root = new TreeNode(vec[i]);
        i++;

        root->left = solve (vec, mini, root->val, i);
        root->right = solve (vec, root->val, maxi, i);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        int mini = INT_MIN;
        int maxi = INT_MAX;
        int i=0;

        return solve (preorder, mini, maxi, i);
    }
};