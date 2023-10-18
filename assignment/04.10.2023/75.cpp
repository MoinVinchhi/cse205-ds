class Solution {
public:
    void merge(vector<int> &vec, int s, int e) {

        int mid = s + (e-s)/2;

        int len1 = mid - s + 1;
        int len2 = e - mid;

        int arr1[len1];
        int arr2[len2];
        int mainI = s;

        for (int i=0; i<len1; i++) {
            arr1[i] = vec[mainI++];
        }
        for (int i=0; i<len2; i++) {
            arr2[i] = vec[mainI++];
        }

        mainI = s;
        int lenn1 = 0;
        int lenn2 = 0;

        while (lenn1<len1 && lenn2<len2) {

            if (arr1[lenn1] <= arr2[lenn2]) {
                vec[mainI++] = arr1[lenn1++];
            }
            else {
                vec[mainI++] = arr2[lenn2++];
            }
        }
        while (lenn1<len1) {
            vec[mainI++] = arr1[lenn1++];
        }
        while (lenn2<len2) {
            vec[mainI++] = arr2[lenn2++];
        }
    }

    void mergeSort(vector<int> &vec, int s, int e) {

        if (s>=e) return;

        int mid = s + (e-s)/2;

        mergeSort(vec, s, mid);
        mergeSort(vec, mid+1, e);

        merge(vec, s, e);
    }

    void sortColors(vector<int>& nums) {

        mergeSort(nums, 0, nums.size()-1);
    }
};