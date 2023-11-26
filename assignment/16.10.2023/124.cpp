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
    //1 root->val
    //2 max path through left child + node val
    //3 max path through right child + node val
    //4 max path through left child + right child + node val

    int maxPathSumUtil (TreeNode* root, int &ans) {

        if (root==NULL) {
            return 0;
        }

        int left = maxPathSumUtil(root->left, ans);
        int right = maxPathSumUtil(root->right, ans);

        int nodeMax = max ( max(root->val, root->val + left + right),
                            max(root->val + left, root->val + right) );
        
        ans = max (ans, nodeMax);

        int singlePathSum = max(root->val, max(root->val+left, root->val+right));
        
        return singlePathSum;
    }

    int maxPathSum(TreeNode* root) {
        
        int ans = INT_MIN;
        maxPathSumUtil (root, ans);

        return ans;
    }
};