class Solution {
public:

    bool help (vector<vector<char>>& board, int i, int j) {

        for (int a=i; a<i+3; a++) {

            for (int b=j; b<j+3; b++) {

                if (board[a][b] != '.'){

                    for (int c=i; c<i+3; c++) {

                        for (int d=j; d<j+3; d++) {

                            if (board[a][b] == board[c][d] && b!=d) {

                                return true;
                            }
                        }
                    }
                }
            }
        }
        return false;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        
        for (int i=0; i<9; i++) {

            for (int j=0; j<9; j++) {

                if (board[i][j] != '.') {
                    for (int k=0; k<9; k++) {

                        if (board[i][k] == board[i][j] && k!=j) {
                            return false;
                        }
                        if (board[k][j] == board[i][j] && k!=i) {
                            return false;
                        }
                    }
                }
            }
        }

        for (int i=0; i<9; i=i+3) {

            for (int j=0; j<9; j=j+3) {
                
                //help function returns true, if there is any repeated character
                if (help(board, i, j))
                    return false;
            }
        }       
        return true;
    }
};