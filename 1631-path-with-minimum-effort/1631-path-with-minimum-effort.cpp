class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;
        dist[0][0] = 0;
        pq.push({0, {0, 0}});
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        while(!pq.empty()) {
            auto [effort, pos] = pq.top();
            auto [row, col] = pos;
            pq.pop();
            if(effort > dist[row][col]) continue;
            if(row == m - 1 && col == n - 1) return effort;
            for(int k = 0; k < 4; k++) {
                int nr = row + dr[k];
                int nc = col + dc[k];
                if(nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    int diff = abs(heights[row][col] - heights[nr][nc]);
                    int newEffort = max(effort, diff);
                    if(newEffort < dist[nr][nc]) {
                        dist[nr][nc] = newEffort;
                        pq.push({newEffort, {nr, nc}});
                    }
                }
            }
        }
        return -1;
    }
};