class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] || grid[n-1][n-1]){
            return -1;
        }
        vector<vector<int>> vis(n, vector<int> (n, 0));
        queue<pair<int,pair<int,int>>> q;
        q.push({1, {0,0}});
        vis[0][0] = 1;
        while(!q.empty()){
            auto [d, index] = q.front();
            auto [i, j] = index;
            q.pop();
            if(i == n-1 && j == n-1) return d;
            if(i-1 >= 0 && j-1 >= 0 && !vis[i-1][j-1] && grid[i-1][j-1] == 0){
                q.push({d+1, {i-1, j-1}});
                vis[i-1][j-1] = 1;
            }
            if(i-1 >= 0 && !vis[i-1][j] && grid[i-1][j] == 0){
                q.push({d+1, {i-1, j}});
                vis[i-1][j] = 1;
            }
            if(i-1 >=0 && j+1 < n && !vis[i-1][j+1] && grid[i-1][j+1] == 0){
                q.push({d+1, {i-1, j+1}});
                vis[i-1][j+1] = 1;
            }
            if(j-1 >= 0 && !vis[i][j-1] && grid[i][j-1] == 0){
                q.push({d+1, {i, j-1}});
                vis[i][j-1] = 1;
            }
            if(j+1 < n && !vis[i][j+1] && grid[i][j+1] == 0){
                q.push({d+1, {i, j+1}});
                vis[i][j+1] = 1;
            }
            if(i+1 < n && j-1 >= 0 && !vis[i+1][j-1] && grid[i+1][j-1] == 0){
                q.push({d+1, {i+1, j-1}});
                vis[i+1][j-1] = 1;
            }
            if(i+1 < n && !vis[i+1][j] && grid[i+1][j] == 0){
                q.push({d+1, {i+1, j}});
                vis[i+1][j] = 1;
            }
            if(i+1 < n && j+1 < n && !vis[i+1][j+1] && grid[i+1][j+1] == 0){
                q.push({d+1, {i+1, j+1}});
                vis[i+1][j+1] = 1;
            }
        }
        return -1;
    }
};