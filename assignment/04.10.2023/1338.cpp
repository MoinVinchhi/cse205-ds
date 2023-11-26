class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int x = arr.size()/2;

        unordered_map<int,int> mp;

        for(int i: arr){
            mp[i]++;
        }

        priority_queue<int> pq;
        for(auto x: mp){
            pq.push(x.second);
        }

        int ans = 0;
        while(!pq.empty() && x > 0){
            int y = pq.top();
            pq.pop();

            x -= y;
            ans++;
        }

        return ans;


    }
};