class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> dist(n,vector<int>(m,0));
        vector<vector<int>> visited(n,vector<int>(m,0));
        for(int i = 0; i<n; i++){
            for(int j =0; j<m; j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    dist[i][j]=0;
                } 
            }
        }
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,-1,0,1};
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int count = q.front().second;
            q.pop();
            for(int i =0; i<4; i++){
                int newRow = r+drow[i];
                int newCol = c+dcol[i];
                if(newRow>=0 && newRow<n && newCol>=0 && newCol<m){
                    if(!visited[newRow][newCol] && mat[newRow][newCol] == 1){
                        visited[newRow][newCol] =1;
                        dist[newRow][newCol] = count+1;
                        q.push({{newRow,newCol},count+1});
                    }
                }
            }
        }
        return dist;
    }
};