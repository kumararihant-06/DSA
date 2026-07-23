class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]==1) return -1;
        queue<pair<int,pair<int,int>>> q;
        int n = grid.size();
        if(n==1 && grid[0][0]==0) return 1;
        vector<vector<int>> dist(n, vector<int>(n,1e9));
        dist[0][0] = 1;
        q.push({1,{0,0}});
        int drow[] = {-1,0,1,0,1,1,-1,-1};
        int dcol[] = {0,-1,0,1,1,-1,1,-1};
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;

            for(int i =0;i<8;i++){
                int newR = r+drow[i];
                int newC = c+dcol[i];

                if(newR>=0 && newR<n && newC>=0 && newC<n && grid[newR][newC] == 0 && dis+1<dist[newR][newC]){
                    dist[newR][newC] = dis+1;
                    if(newR == n-1 && newC == n-1) return dis+1;
                    q.push({dis+1,{newR,newC}});
                }
            }
        }
        return -1;
    }
};