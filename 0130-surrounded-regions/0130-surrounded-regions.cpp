class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& board){
        vis[row][col] = 1;
        if(row-1 >= 0 && !vis[row-1][col] && board[row-1][col] == 'O'){
            dfs(row-1, col, vis, board);
        }
        if(row+1 < board.size() && !vis[row+1][col] && board[row+1][col] == 'O'){
            dfs(row+1, col, vis, board);
        }
        if(col-1 >= 0 && !vis[row][col-1] && board[row][col-1] == 'O'){
            dfs(row, col-1, vis, board);
        }
        if(col+1 < board[row].size() && !vis[row][col+1] && board[row][col+1] == 'O'){
            dfs(row, col+1, vis, board);
        }
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        for(int col = 0; col < n; col++){
            if(!vis[0][col] && board[0][col] == 'O'){
                dfs(0, col, vis, board);
            }
        }
        for(int col = 0; col < n; col++){
            if(!vis[m-1][col] && board[m-1][col] == 'O'){
                dfs(m-1, col, vis, board);
            }
        }
        for(int row = 0; row < m; row++){
            if(!vis[row][0] && board[row][0] == 'O'){
                dfs(row, 0, vis, board);
            }
        }
        for(int row = 0; row < m; row++){
            if(!vis[row][n-1] && board[row][n-1] == 'O'){
                dfs(row, n-1, vis, board);
            }
        }
        for(int row = 1; row < m-1; row++){
            for(int col = 1; col < n-1; col++){
                if(!vis[row][col] && board[row][col] == 'O'){
                    board[row][col] = 'X';
                }
            }
        }
    }
};