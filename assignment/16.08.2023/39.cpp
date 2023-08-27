class Solution {

private:
    void solve(int i, int t, vector<int> candidates, vector<int> temp, vector<vector<int>>& ans){

        // base case
        if (t==0){
            ans.push_back(temp);
            return;
        }

        if (i == candidates.size()){
            if (t==0){
                ans.push_back(temp);
            }
            return;
        }

        // pick
        if (candidates[i] <= t){
            temp.push_back(candidates[i]);
            solve(i, t-candidates[i], candidates, temp, ans);
            temp.pop_back();
        }

        // not pick
        solve(i+1, t, candidates, temp, ans);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<int> temp;
        vector<vector<int>> ans;

        solve(0, target, candidates, temp, ans);

        return ans;
    }
};