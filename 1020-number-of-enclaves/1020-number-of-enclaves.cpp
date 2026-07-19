class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        queue<pair<int,int>> q;
        for(int i = 0; i<n ;i++){
            if(i==0 || i==n-1){
                for(int j = 0; j<m; j++){
                    if(grid[i][j]==1){
                        q.push({i,j});
                        grid[i][j] = 2;
                    }
                }
            }else{
                if(grid[i][0]==1){
                    q.push({i,0});
                    grid[i][0]=2;
                } 
                if(grid[i][m-1]==1){
                    q.push({i,m-1});
                    grid[i][m-1]=2;
                } 
            }
        }
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,-1,0,1};
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nRow = row+drow[i];
                int nCol = col+dcol[i];
                if(nRow>=0 && nRow<n && nCol>=0 && nCol<m){
                    if(grid[nRow][nCol]==1){
                        q.push({nRow,nCol});
                        grid[nRow][nCol]=2;
                    }
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1) count++;
            }
        }
        return count;
    }
};