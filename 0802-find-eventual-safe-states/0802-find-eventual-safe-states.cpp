class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> reverseGraph(n);
        for(int i = 0; i < n; i++){
            for(auto ad : graph[i]){
                reverseGraph[ad].push_back(i);
            }
        }
        vector<int> outDegree(n, 0);
        queue<int> q;
        for(int i = 0; i < n; i++){
            outDegree[i] += graph[i].size();
            if(outDegree[i] == 0) q.push(i);
        }
        vector<int> safe(n, 0);
        while(!q.empty()){
            int node = q.front();
            q.pop();

            safe[node] = 1;

            for(auto prev : reverseGraph[node]){
                outDegree[prev]--;

                if(outDegree[prev] == 0){
                    q.push(prev);
                }
            }
        }
        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(safe[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};