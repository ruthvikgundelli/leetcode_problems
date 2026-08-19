class Solution {
public: 
    void bfs(int m, int n, int& minutes, vector<vector<int>>& vis, vector<vector<int>>& grid){
        queue<pair<pair<int,int>,int>> q;
        for(int row = 0; row < m; row++){
            for(int col = 0; col < n; col++){
                if(grid[row][col] == 2){
                    vis[row][col] = 2;
                    q.push({{row,col}, minutes});
                }
            }
        }
        while(!q.empty()){
            auto [pos, time] = q.front();
            auto [row, col] = pos;
            q.pop();
            if(row-1 >= 0 && !vis[row-1][col] && grid[row-1][col] == 1){
                vis[row-1][col] = 2;
                q.push({{row-1, col}, time + 1});
            }
            if(row+1 < m && !vis[row+1][col] && grid[row+1][col] == 1){
                vis[row+1][col] = 2;
                q.push({{row+1, col}, time + 1});
            }
            if(col-1 >= 0 && !vis[row][col-1] && grid[row][col-1] == 1){
                vis[row][col-1] = 2;
                q.push({{row, col-1}, time + 1});
            }
            if(col+1 < n && !vis[row][col+1] && grid[row][col+1] == 1){
                vis[row][col+1] = 2;
                q.push({{row, col+1}, time + 1});
            }
            minutes = time;
        }
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        int minutes = 0;
        bfs(m, n, minutes, vis, grid);
        for(int row = 0; row < m; row++){
            for(int col = 0; col < n; col++){
                if(grid[row][col] == 1 && !vis[row][col]) return -1;
            }
        }
        return minutes;
    }
};