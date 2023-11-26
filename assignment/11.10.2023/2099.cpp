class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {

        priority_queue<pair<int,int>>pq;

        for(int i=0;i<nums.size();i++){
            pq.push({nums[i],i});
        }

        vector<pair<int,int>>ans;

        while(!pq.empty() && k--) {
            ans.push_back({pq.top().second,pq.top().first});
            pq.pop();
        }
        
        sort(ans.begin(),ans.end());
        vector<int>res;

        for (int i=0;i<ans.size();i++) {
            res.push_back(ans[i].second);
        }
        
        return res;
    }
};