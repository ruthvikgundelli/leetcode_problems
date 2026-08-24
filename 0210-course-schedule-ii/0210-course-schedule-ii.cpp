class Solution {
public: // USED Kahn's Algorithm
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto p : prerequisites){
            int a = p[0];
            int b = p[1];
            adj[b].push_back(a);
        }
        vector<int> inDegree(numCourses, 0);
        for(int i = 0; i < adj.size(); i++){
            for(auto ad : adj[i]){
                inDegree[ad]++;
            }
        }
        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(inDegree[i] == 0) q.push(i);
        }
        vector<int> ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto ad : adj[node]){
                inDegree[ad]--;
                if(inDegree[ad] == 0) q.push(ad);
            }
            ans.push_back(node);
        }
        if(ans.size() == numCourses) return ans;
        return {};
    }   
};