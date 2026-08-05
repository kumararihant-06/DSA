class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        
        vector<vector<int>> adj(n);
        for (auto edge: invocations){
            int a = edge[0];
            int b = edge[1];
            adj[a].push_back(b);
        }

        vector<int> suspicious(n,0);
        queue<int> q;
        q.push(k);
        suspicious[k] = 1;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto edge: adj[node]){
                if(!suspicious[edge]){
                    suspicious[edge] = 1;
                    q.push(edge);
                }
            }
        }

        for(auto edge: invocations){
            int a = edge[0];
            int b = edge[1];
            if(!suspicious[a]&&suspicious[b]){
                vector<int> answer;
                for(int i = 0; i<n; i++){
                    answer.push_back(i);
                }
                return answer;
            }
        }

        vector<int> answer;
        for(int i =0; i<n; i++){
            if(!suspicious[i]){
                answer.push_back(i);
            }
        }
        return answer;
    }
};