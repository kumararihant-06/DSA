class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        queue <pair<int, int>> q;
        vector<vector<int>> visited(n,vector<int>(m,0));

        for (int i = 0; i<n; i++){
            if(i==0 || i==n-1){
                for(int j =0 ;j<m;j++){
                    if(board[i][j]=='O') q.push({i,j});
                }
            }else{
                if(board[i][0]=='O'){
                    q.push({i,0});
                }
                if(board[i][m-1]=='O'){
                    q.push({i,m-1});
                }
            }
        }
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,-1,0,1};
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            visited[row][col] = 1;
            q.pop();
            for(int i = 0; i<4; i++){
                int nRow = row+drow[i];
                int nCol = col+dcol[i];
                if(nRow>=0 && nRow<n && nCol>=0 && nCol<m){
                    if(board[nRow][nCol]=='O' && !visited[nRow][nCol]){
                    visited[nRow][nCol] = 1;
                    q.push({nRow,nCol});
                }
                } 
            }    
        }
        for(int i = 0; i<n; i++){
            for(int j = 0;j<m;j++){
                if(visited[i][j]){
                    board[i][j] = 'O';
                }else{
                    board[i][j]='X';
                }
            }
        }
    }
};