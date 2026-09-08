class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto edge : flights){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            adj[u].push_back({v, wt});
        }
        queue<pair<int, pair<int,int>>> q;
        // {stops, {cost, node}}
        q.push({0, {0, src}});
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        while(!q.empty()){
            auto [stops, index] = q.front();
            auto [cost, node] = index;
            q.pop();
            if(stops > k) continue;
            for(auto ad : adj[node]){
                int next = ad.first;
                int wt = ad.second;
                if(cost + wt < dist[next]){
                    dist[next] = cost + wt;
                    q.push({
                        stops + 1,
                        {dist[next], next}
                    });
                }
            }
        }
        if(dist[dst] == INT_MAX) return -1;
        return dist[dst];
    }
};