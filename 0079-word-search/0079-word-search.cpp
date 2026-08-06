class Solution {
public:
    bool dfs(int row, int col, int index, const string& word, vector<vector<char>>& board){
        if(index == word.size()) return true;

        if(row < 0 || row >= board.size() || col < 0 || col >= board[0].size()) return false;
        if(board[row][col] != word[index]) return false;

        char temp = board[row][col];
        board[row][col] = '#';
        bool found =
            dfs(row + 1, col, index + 1, word, board) ||
            dfs(row - 1, col, index + 1, word, board) ||
            dfs(row, col + 1, index + 1, word, board) ||
            dfs(row, col - 1, index + 1, word, board);
        board[row][col] = temp;

        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(dfs(i,j,0,word,board)) return true;
            }
        }
        return false;
    }
};