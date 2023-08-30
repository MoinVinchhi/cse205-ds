class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int s = INT_MIN;
        int sum = 0;
        
        for (auto i : nums){

            sum += i;
            s = max(s, sum);

            // if the current sum becomes negative, it means that including the current element in the subarray would decrease the sum. In such cases, we reset sum to 0, effectively starting a new potential subarray.
            if (sum < 0){
                sum = 0;
            }
        }
        return s;
    }
};