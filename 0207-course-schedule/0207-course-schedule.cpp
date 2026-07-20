class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> inDegree(numCourses,0);
        queue<int> q;
        for( auto prerequisite : prerequisites){
            int course = prerequisite[0];
            int pre = prerequisite[1];

            adj[course].push_back(pre);
            inDegree[pre]++;
        }
        for(int i=0; i<inDegree.size();i++){
            if(inDegree[i]==0) q.push(i);
        }

        int count = 0;
        while(!q.empty()){
            int course = q.front();
            q.pop();

            count++;
            for(auto nextCourse: adj[course]){
                inDegree[nextCourse]--;
                if(inDegree[nextCourse]==0)q.push(nextCourse);
            }
        }
        if(count == numCourses) return true;
        return false;
    }
};