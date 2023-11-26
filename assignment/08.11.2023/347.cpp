class Solution {
public:
    static bool cmp(pair<int, int>& a, pair<int, int>& b) {
        return a.second > b.second; // Sorting in descending order of frequency
    }
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mp;
        for (auto i : nums) {
            mp[i]++;
        }
        
        vector<pair<int, int>> A;
        for (auto i : mp) {
            A.push_back(i);
        }
        
        sort(A.begin(), A.end(), cmp); // Sort the vector based on frequency
        
        int count = 0;
        vector<int> v;
        for (auto it : A) {
            v.push_back(it.first);
            count++;
            if (count == k)
                break;
        }
        return v;
    }
};