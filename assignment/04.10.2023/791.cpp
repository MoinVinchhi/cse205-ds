class Solution {
public:
    string customSortString(string order, string s) {
        map<char,int>m;
        for(auto it:s){
            m[it]++;
        }

        string ans="";
        for(auto it:order){
            while(m[it]--){
                ans+=it;
            }
        }
        for(auto it:m){
            while(it.second>0){
                it.second--;
                ans+=it.first;
            }
        }
        return ans;
    }
};