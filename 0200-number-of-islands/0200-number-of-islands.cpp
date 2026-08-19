class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& grid){
        vis[row][col] = 1;
        int m = grid.size();
        int n = grid[0].size();
        if(row - 1 >= 0 && !vis[row-1][col] && grid[row-1][col] == '1'){
            dfs(row-1, col, vis, grid);
        }
        if(row + 1 < m && !vis[row+1][col] && grid[row+1][col] == '1'){
            dfs(row+1, col, vis, grid);
        }
        if(col - 1 >= 0 && !vis[row][col-1] && grid[row][col-1] == '1'){
            dfs(row, col-1, vis, grid);
        }
        if(col + 1 < n && !vis[row][col+1] && grid[row][col+1] == '1'){
            dfs(row, col+1, vis, grid);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int island = 0;
        vector<vector<int>> vis(m, vector<int> (n, 0));
        for(int row = 0; row < m; row++){
            for(int col = 0; col < n; col++){
                if(!vis[row][col] && grid[row][col] == '1'){
                    island++;
                    dfs(row, col, vis, grid);
                }
            }
        }
        return island;
    }
};