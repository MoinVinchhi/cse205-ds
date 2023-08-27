class Solution {

private:
    void solve(string str, int o, int c, vector<string>& ans, int n){

        // base case
        if (str.length() == 2*n){

            ans.push_back(str);
            return;
        }

        if (o < n){
            solve (str + "(", o+1, c, ans, n);
        }
        if (c < o){
            solve (str + ")", o, c+1, ans, n);
        }
    }

public:
    vector<string> generateParenthesis(int n) {

        vector<string> ans;

        solve("(", 1, 0, ans, n);
        
        return ans;
    }
};