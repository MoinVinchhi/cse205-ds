class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {

        unordered_map<int,int> mp;

        for (int i : nums) {
            mp[i]++;
        }        

        int missedNo, repeatedNo;

        for (int i=1; i<=nums.size(); i++) {

            if (mp[i]==0) {
                missedNo = i;
            }
            if (mp[i]==2) {
                repeatedNo = i;
            }
        }

        vector<int> ans;
        ans.push_back(repeatedNo);
        ans.push_back(missedNo);

        return ans;
    }
};