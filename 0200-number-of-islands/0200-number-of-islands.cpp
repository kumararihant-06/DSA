class Solution {
public:
    void dfs(int n, int m, vector<vector<bool>>& isVisited, vector<vector<char>>& grid, int i, int j){
        if(i>=n or j>=m || i<0 || j<0 || isVisited[i][j] || grid[i][j]!='1') return;


        isVisited[i][j]= true;

        dfs(n, m, isVisited, grid, i+1, j);
        dfs(n, m, isVisited, grid, i-1, j);
        dfs(n, m, isVisited, grid, i, j+1);
        dfs(n, m, isVisited, grid, i, j-1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int land= 0;
        int n= grid.size();
        int m= grid[0].size();

        vector<vector<bool>> isVisited(n, vector<bool>(m, false));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!isVisited[i][j] && grid[i][j]=='1'){
                    dfs(n, m, isVisited, grid, i, j);
                    land++;
                }
            }
        }
        return land;
    }
};
