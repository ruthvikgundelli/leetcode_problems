class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        queue<int> q;
        for(int i = 0; i < n; i++){
            if(color[i] != -1) continue;
            q.push(i);
            color[i] = 0;
            while(!q.empty()){
                int node = q.front();
                q.pop();
                for(auto ad : graph[node]){
                    if(color[ad] == color[node]){
                        return false;
                    }
                    else if(color[ad] == -1){
                        if(color[node] == 0) color[ad] = 1;
                        else color[ad] = 0;
                        q.push(ad);
                    }
                }
            }
        }
        return true;
    }
};