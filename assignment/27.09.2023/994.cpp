class Solution {
public:
    bool check(int i,int j,int row,int col){
        return (i>-1 && i<row && j>-1 && j<col);
    }
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int,int>,int>>q;
        int good_or=0;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                   good_or++;
                }
                else if(grid[i][j]==2){
                    q.push({{i,j},0});
                }
            }
        }
        int i,j,timer=0;
        while(!q.empty()){
            i=q.front().first.first;
            j=q.front().first.second;
            timer=q.front().second;
            q.pop();
            if(check(i-1,j,n,m) && grid[i-1][j]==1){
                  grid[i-1][j]=0;
                  good_or--;
                  q.push({{i-1,j},timer+1});
            }
            if(check(i+1,j,n,m) && grid[i+1][j]==1){
                  grid[i+1][j]=0;
                  good_or--;
                  q.push({{i+1,j},timer+1});
            }
            if(check(i,j-1,n,m) && grid[i][j-1]==1){
                  grid[i][j-1]=0;
                  good_or--;
                  q.push({{i,j-1},timer+1});
            }
            if(check(i,j+1,n,m) && grid[i][j+1]==1){
                  grid[i][j+1]=0;
                  good_or--;
                  q.push({{i,j+1},timer+1});
            }
        }
        if(good_or){
            return -1;
        }
        return timer;
    }
};