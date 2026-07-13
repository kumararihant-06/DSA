class Solution {
public:
    void countProvinces(int node, vector<vector<int>>& isConnected, vector<bool>& visited){
        visited[node] = 1;
        for(int j =0; j<isConnected[node].size();j++){
            if(isConnected[node][j]&&!visited[j]){
                visited[j] = 1;
                countProvinces(j,isConnected,visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<bool> visited(isConnected.size(),0);
        int count = 0;

        for(int i = 0; i<isConnected.size();i++){
            if(!visited[i]){
                count++;
                countProvinces(i,isConnected,visited);
            }
        }
        return count;
    }
};