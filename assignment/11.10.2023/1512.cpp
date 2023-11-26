class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        
        unordered_map<int,int> mp;

        int cnt=0;

        for (int i : nums) {
            if (mp.count(i)) {
                cnt = cnt + mp[i];
            }
            mp[i]++;
        }
        return cnt;
    }
};