class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>>adj[n+1];
        for(auto it: times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> timeTaken(n+1,1e9);
        timeTaken[k] = 0;
        pq.push({0,k});
        while(!pq.empty()){
            auto it = pq.top();
            int time = it.first;
            int node = it.second;
            pq.pop();

            for(auto it: adj[node]){
                int nodeTime = it.second;
                int adjNode = it.first;
                if(nodeTime+time<timeTaken[adjNode]){
                    timeTaken[adjNode] = nodeTime+time;
                    pq.push({nodeTime+time, adjNode});
                }
            }
        }
        int minTime = 0;
        for(int i = 1; i<=n;i++){
            if(timeTaken[i]==1e9) return -1;
            minTime = max(minTime,timeTaken[i]);
        }
        return minTime;
    }
};