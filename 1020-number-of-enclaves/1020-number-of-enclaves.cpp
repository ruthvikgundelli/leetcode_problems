class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<int>>& grid){
        vis[row][col] = 1;
        if(row-1 >= 0 && !vis[row-1][col] && grid[row-1][col] == 1){
            dfs(row-1, col, vis, grid);
        }
        if(row+1 < grid.size() && !vis[row+1][col] && grid[row+1][col] == 1){
            dfs(row+1, col, vis, grid);
        }
        if(col-1 >= 0 && !vis[row][col-1] && grid[row][col-1] == 1){
            dfs(row, col-1, vis, grid);
        }
        if(col+1 < grid[row].size() && !vis[row][col+1] && grid[row][col+1] == 1){
            dfs(row, col+1, vis, grid);
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        for(int col = 0; col < n; col++){
            if(grid[0][col] == 1 && !vis[0][col]){
                dfs(0, col, vis, grid);
            }
            if(grid[m-1][col] == 1 && !vis[m-1][col]){
                dfs(m-1, col, vis, grid);
            }
        }
        for(int row = 0; row < m; row++){
            if(grid[row][0] == 1 && !vis[row][0]){
                dfs(row, 0, vis, grid);
            }
            if(grid[row][n-1] == 1 && !vis[row][n-1]){
                dfs(row, n-1, vis, grid);
            }
        }
        int ans = 0;
        for(int row = 0; row < m; row++){
            for(int col = 0; col < n; col++){
                if(grid[row][col] == 1 && !vis[row][col]){
                    ans++;
                }
            }
        }
        return ans;
    }
};