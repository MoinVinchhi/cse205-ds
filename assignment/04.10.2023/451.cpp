class Solution {
public:
    string frequencySort(string s) {

        unordered_map<char,int> mp;

        for (auto i : s) {
            mp[i]++;
        }

        vector<pair<int,char>> vec;

        for (auto it : mp) {
            vec.push_back({it.second,it.first});
        }

        sort(vec.rbegin(), vec.rend());

        string ans;

        for (auto i : vec) {
            int temp = i.first;
            while (temp--) {
                ans += i.second;
            }
        }

        return ans;
    }
};