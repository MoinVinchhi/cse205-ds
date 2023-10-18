class Solution {
public:
    void merge(vector<int> &v, int s, int e) {
        
        int mid = (s+e)/2;

        int len1 = mid-s+1;
        int len2 = e - mid;

        int first[len1];
        int second[len2];

        int mainI = s;

        for (int i=0; i<len1; i++) {
            first[i] = v[mainI];
            mainI++;
        }

        for (int i=0; i<len2; i++) {
            second[i] = v[mainI];
            mainI++;
        }

        mainI = s;
        int lenn1 = 0;
        int lenn2 = 0;

        while (lenn1<len1 && lenn2<len2) {
            if (first[lenn1] < second[lenn2]) {
                
                v[mainI] = first[lenn1];
                mainI++;
                lenn1++;
            }
            else {
                v[mainI] = second[lenn2];
                mainI++;
                lenn2++;
            }
        }
        while (lenn1 < len1) {

            v[mainI] = first[lenn1];
            mainI++;
            lenn1++;
        }
        while (lenn2 < len2) {

            v[mainI] = second[lenn2];
            mainI++;
            lenn2++;
        }
    }

    void mergeSort(vector<int> &v, int s, int e) {

        if (s>=e) {
            return;
        }

        int mid = (s+e)/2;

        mergeSort(v, s, mid);

        mergeSort(v, mid+1, e);

        merge(v, s, e);
    }

    int arrayPairSum(vector<int>& nums) {

        // mergeSort(nums, 0, nums.size()-1);

        sort(nums.begin(), nums.end());
        int sum = 0;

        for (int i=0; i<nums.size()-1; i=i+2) {

            sum += nums[i];
            // sum += min(nums[i], nums[i+1]);
        }        
        return sum;
    }
};