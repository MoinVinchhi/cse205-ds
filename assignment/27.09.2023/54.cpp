class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        vector<int> ans;
        
        int row = matrix.size();
        int col = matrix[0].size();
        
        //index initialization
        int firstRow = 0;
        int lastRow = row-1;
        int firstCol = 0;
        int lastCol = col-1;

        int direction = 0;

        while (firstRow<=lastRow && firstCol<=lastCol) {

            if (direction==0) {
                for (int i=firstCol; i<=lastCol; i++) {

                    ans.push_back(matrix[firstRow][i]);
                }
                firstRow++;
            }

            else if (direction==1) {
                for (int i=firstRow; i<=lastRow; i++) {

                    ans.push_back(matrix[i][lastCol]);
                }
                lastCol--;
            }

            else if (direction==2) {
                for (int i=lastCol; i>=firstCol; i--) {

                    ans.push_back(matrix[lastRow][i]);
                }
                lastRow--;
            }

            else {
                for (int i=lastRow; i>=firstRow; i--) {

                    ans.push_back(matrix[i][firstCol]);
                }
                firstCol++;
            }

            direction = (direction+1) % 4; //direction will only 0,1,2,3
        }

        return ans;
    }
};