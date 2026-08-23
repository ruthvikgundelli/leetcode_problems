class Solution {
public: 
    bool dfs(int i, vector<vector<int>>& adj, vector<int>& vis, vector<int>& path){
        vis[i] = 1;
        path[i] = 1;
        for(auto ad : adj[i]){
            if(!vis[ad]){
                if(dfs(ad, adj, vis, path)) return true;
            }
            else if(path[ad]) return true;
        }
        path[i] = 0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto p : prerequisites){
            int a = p[0];
            int b = p[1];
            adj[b].push_back(a);
        }
        vector<int> vis(numCourses, 0);
        vector<int> path(numCourses, 0);
        for(int i = 0; i < numCourses; i++){
            if(!vis[i]){
                if(dfs(i, adj, vis, path)){
                    return false;
                }
            }
        }
        return true;
    }
};