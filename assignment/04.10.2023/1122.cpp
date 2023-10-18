class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {

        vector<int> count(1001,0); // Numbers are from 0 to 1000;

        for (int i=0; i<arr1.size(); i++) {
            count[arr1[i]]++;
        }

        int n = 0;
        // To follow the same ordering of arr2
        for (int i=0; i<arr2.size(); i++) {
            while (count[arr2[i]]-->0) {
                arr1[n] = arr2[i];
                n++;
            }
        }
        // For remaining elements that were not in arr2
        for (int i=0; i<1001; i++) {
            while (count[i]-->0) {
                arr1[n] = i;
                n++;
            }
        }

        return arr1;
    }
};