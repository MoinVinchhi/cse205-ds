class Solution {
public:
    int partition(vector<int> &vec, int s, int e) {

        int pivot = vec[s];

        int count = 0;

        for (int i=s+1; i<vec.size(); i++) {

            if (vec[i]<=pivot) count++;
        }

        int index = s + count;
        swap(vec[index], vec[s]);

        int i=s, j=e;

        while (i<index && j>index) {
            
            while (vec[i]<=pivot) {
                i++;
            }

            while (vec[j]>pivot) {
                j--;
            }

            if (i<index && j>index) {
                swap(vec[i], vec[j]);
            }

        }
        return index;

    }

    void quickSort(vector<int> &vec, int s, int e) {

        if (s>=e) return;

        int p = partition(vec, s, e);

        quickSort(vec, s, p-1);
        quickSort(vec, p+1, e);
    }

    int missingNumber(vector<int>& nums) {

        quickSort(nums, 0, nums.size()-1);

        int n = nums.size();

        int m = 0;
        int ans;

        for (int i=0; i<n; i++) {

            if(i!=nums[m] && m<=n) {
                ans = i;
                break;
            }
            m++;
        }
        return ans;
    }
};