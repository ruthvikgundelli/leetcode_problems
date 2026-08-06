class Solution {
public:
    bool dfs(int row, int col, int index, int m, int n, string word, vector<vector<char>>& board){
        if(index == word.size()) return true;

        if(row < 0 || row >= m || col < 0 || col >= n) return false;
        if(board[row][col] != word[index]) return false;

        char temp = board[row][col];
        board[row][col] = '#';
        bool found =
            dfs(row + 1, col, index + 1, m, n, word, board) ||
            dfs(row - 1, col, index + 1, m, n, word, board) ||
            dfs(row, col + 1, index + 1, m, n, word, board) ||
            dfs(row, col - 1, index + 1, m, n, word, board);
        board[row][col] = temp;

        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(dfs(i,j,0,m,n,word,board)) return true;
            }
        }
        return false;
    }
};