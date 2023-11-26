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

    int findPos (vector<int> in, int n, int ele) {

        for (int i=0; i<n; i++) {
            if (in[i] == ele) {
                return i;
            }
        }
        return -1;
    }

    TreeNode* solve (vector<int> pre, vector<int> in, int n, int &index, int inStart, int inEnd) {

        //base case
        if (index >= n || inStart > inEnd) {
            return NULL;
        }

        int element = pre[index];
        index++;
        TreeNode* root = new TreeNode(element);
        int pos = findPos(in, n, element);

        //recursive calls
        root->left = solve (pre, in, n, index, inStart, pos-1);
        root->right = solve (pre, in, n, index, pos+1, inEnd);

        return root;
    }

    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        
        int n = pre.size();

        int preOrderIndex = 0;
        TreeNode* ans = solve (pre, in, n, preOrderIndex, 0, n-1);

        return ans;
    }


    // 2nd method------------------------------------------------

    // void buildMap (vector<int> in, map<int,int> &mp, int n) {

    //     for (int i=0; i<n; i++) {
    //         mp[in[i]] = i;
    //     }
    // }

    // int findPos (vector<int> in, int n, int ele) {

    //     for (int i=0; i<n; i++) {
    //         if (in[i] == ele) {
    //             return i;
    //         }
    //     }
    //     return -1;
    // }

    // TreeNode* solve (vector<int> pre, vector<int> in, int n, int &index, int inStart, int inEnd, map <int,int> mp) {

    //     //base case
    //     if (index >= n || inStart > inEnd) {
    //         return NULL;
    //     }

    //     int element = pre[index];
    //     index++;
    //     TreeNode* root = new TreeNode(element);

    //     int pos = mp[element];

    //     //recursive calls
    //     root->left = solve (pre, in, n, index, inStart, pos-1, mp);
    //     root->right = solve (pre, in, n, index, pos+1, inEnd, mp);

    //     return root;
    // }

    // TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        
    //     int n = pre.size();

    //     //for mapping inorder
    //     map <int,int> mp;
    //     buildMap(in, mp, n);


    //     int preOrderIndex = 0;
    //     TreeNode* ans = solve (pre, in, n, preOrderIndex, 0, n-1, mp);

    //     return ans;
    // }

};