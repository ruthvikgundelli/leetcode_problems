class Solution {
public:
    void dfs(int sr, int sc, int prev, int color, vector<vector<int>>& vis, vector<vector<int>>& image){
        vis[sr][sc] = 1;
        image[sr][sc] = color;
        if(sr-1 >= 0 && !vis[sr-1][sc] && image[sr-1][sc] == prev){
            dfs(sr-1, sc, prev, color, vis, image);
        }
        if(sr+1 < image.size() && !vis[sr+1][sc] && image[sr+1][sc] == prev){
            dfs(sr+1, sc, prev, color, vis, image);
        }
        if(sc-1 >= 0 && !vis[sr][sc-1] && image[sr][sc-1] == prev){
            dfs(sr, sc-1, prev, color, vis, image);
        }
        if(sc+1 < image[0].size() && !vis[sr][sc+1] && image[sr][sc+1] == prev){
            dfs(sr, sc+1, prev, color, vis, image);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        vector<vector<int>> vis(m, vector<int> (n, 0));
        int prev = image[sr][sc];
        dfs(sr, sc, prev, color, vis, image);
        return image;
    }
};