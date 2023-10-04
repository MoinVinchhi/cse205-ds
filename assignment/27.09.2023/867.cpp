class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {

        int n = matrix[0].size();
        int m = matrix.size();
        
        vector<vector<int>> matrixx (n, vector<int> (m));
        
        for (int i=0; i<m; i++) {

            for (int j=0; j<n; j++) {

                matrixx[j][i] = matrix[i][j];
            }
        }

        return matrixx;
    }
};