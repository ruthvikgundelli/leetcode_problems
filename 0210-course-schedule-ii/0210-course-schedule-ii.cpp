class Solution {
public:
    bool dfs(int i, vector<vector<int>>& adj, vector<int>& vis, vector<int>& path, vector<int>& ans){
        vis[i] = 1;
        path[i] = 1;
        for(auto ad : adj[i]){
            if(!vis[ad]){
                if(dfs(ad, adj, vis, path, ans)) return true;
            }
            else if(path[ad]) return true;
        }
        path[i] = 0;
        ans.push_back(i);
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto p : prerequisites){
            int a = p[0];
            int b = p[1];
            adj[b].push_back(a);
        }
        vector<int> vis(numCourses, 0);
        vector<int> path(numCourses, 0);
        vector<int> ans;
        for(int i = 0; i < numCourses; i++){
            if(!vis[i]){
                if(dfs(i, adj, vis, path, ans)){
                    return {};
                }
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;  
    }
};