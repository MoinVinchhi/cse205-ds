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

    int partition(vector<int> &vec, int s, int e) {

        int parity = vec[s];

        int count = 0;

        for (int i=s+1; i<vec.size(); i++) {

            if (vec[i]<=parity) {
                count++;
            }
        }

        int index = s + count;
        swap(vec[s], vec[index]);

        int i=s+1, j=e;

        while (i<index && j>index) {
            
            while (vec[i]<=parity) {
                i++;
            }

            while (vec[j]>parity) {
                j--;
            }

            if (i<index && j>index) {
                swap(vec[i], vec[j]);
            }
        }
        return index;
    }

    void quickSort(vector<int> &vec, int s, int e) {

        if (s>=e)
            return;

        int p = partition(vec, s, e);

        quickSort(vec, s, p-1);
        quickSort(vec, p+1, e);
    }

    vector<int> sortArray(vector<int>& nums) {

        int n = nums.size();

        // mergeSort(nums, 0, n-1);
        quickSort(nums, 0, n-1);

        return nums;
    }
};