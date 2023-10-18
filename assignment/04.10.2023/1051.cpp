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
        int llen1 = 0;
        int llen2 = 0;

        while (llen1<len1 && llen2<len2) {

            if (arr1[llen1]<=arr2[llen2]) {
                vec[mainI++] = arr1[llen1++];
            }

            else {
                vec[mainI++] = arr2[llen2++];
            }
        }

        while (llen1<len1) {
            vec[mainI++] = arr1[llen1++];
        }

        while (llen2<len2) {
            vec[mainI++] = arr2[llen2++];
        }
    }

    void mergeSort(vector<int> &vec, int s, int e) {

        if (s>=e) return;

        int mid = s + (e-s)/2;

        mergeSort(vec, s, mid);
        mergeSort(vec, mid+1, e);

        merge(vec, s, e);
    }

    vector<int> sortt(vector<int> vec) {
        mergeSort(vec);
        sort(vec.begin(), vec.end());
        return vec;
    }

    int heightChecker(vector<int>& heights) {
        int n = heights.size();
        vector<int> ans(n);
        ans = sortt(heights);

        int count = 0;
        for (int i=0; i<n; i++) {
            if (heights[i]!=ans[i]) {
                count++;
            }
        }
        return count;
    }
};