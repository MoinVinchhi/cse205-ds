class Solution {
public:
    void solve(int i, int n,int k,vector<int> &subsets,vector<vector<int>> &ans){
        
        if(k == 0){
            ans.push_back(subsets);
            return;
        }
        
        // because after that we need certain amount of element in combiation
        if(k > n-i+1) {
            return;
        }

        if(i > n){
            return;
        }

        // pick 
        subsets.push_back(i);
        solve(i+1,n,k-1,subsets,ans); // k-1 because we already picked one element

        // not pick
        subsets.pop_back();
        solve(i+1,n,k,subsets,ans);

    }

    vector<vector<int>> combine(int n, int k) {

        vector<int> subsets;
        vector<vector<int>> ans;

        solve(1,n,k,subsets,ans);
        return ans;
    }
};