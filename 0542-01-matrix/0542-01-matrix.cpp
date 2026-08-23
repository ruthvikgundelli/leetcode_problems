class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> ans(m, vector<int>(n, -1));
        queue<pair<int,int>> q;
        for(int row = 0; row < m; row++){
            for(int col = 0; col < n; col++){
                if(mat[row][col] == 0){
                    q.push({row,col});
                    ans[row][col] = 0;
                }
            }
        }
        while(!q.empty()){
            auto [row, col] = q.front();
            q.pop();
            if(row - 1 >= 0 && ans[row-1][col] == -1){
                ans[row-1][col] = ans[row][col] + 1;
                q.push({row-1, col});
            }
            if(row + 1 < m && ans[row+1][col] == -1){
                ans[row+1][col] = ans[row][col] + 1;
                q.push({row+1, col});
            }
            if(col - 1 >= 0 && ans[row][col-1] == -1){
                ans[row][col-1] = ans[row][col] + 1;
                q.push({row, col-1});
            }
            if(col + 1 < n && ans[row][col+1] == -1){
                ans[row][col+1] = ans[row][col] + 1;
                q.push({row, col+1});
            }
        }
        return ans;
    }
};