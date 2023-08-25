class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {

        vector<int> num;
        int j=0;

        // think about worst case -> arr is including 1 to 1000 and k=1000 ---output = 2000
        // so, num length should be 1000+1000
        for (int i=1; i<=1000+1000; i++){
            
            if (j<arr.size() && i == arr[j]){
                j++;
                continue;
            }
            num.push_back(i);
        }
        return num[k-1];
    }
};