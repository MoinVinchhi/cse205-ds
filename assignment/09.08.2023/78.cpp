class Solution {
public:

    vector <vector<int>> ans;

    void sub(vector<int> &num, int i, vector<int> temp){

        if (i==num.size()){

            ans.push_back(temp);
            return;
        }

        sub (num, i+1, temp); //exclude the current element

        temp.push_back(num[i]);

        sub (num, i+1, temp); //include the current element
    }

    vector<vector<int>> subsets(vector<int>& num) {
        
        vector<int> temp;
        
        sub(num, 0, temp);

        return ans;
    }
};