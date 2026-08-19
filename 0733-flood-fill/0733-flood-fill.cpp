class Solution {
public:
    void dfs(int sr, int sc, int prev, int color, vector<vector<int>>& image){
        image[sr][sc] = color;
        if(sr-1 >= 0 && image[sr-1][sc] == prev){
            dfs(sr-1, sc, prev, color, image);
        }
        if(sr+1 < image.size() && image[sr+1][sc] == prev){
            dfs(sr+1, sc, prev, color, image);
        }
        if(sc-1 >= 0 && image[sr][sc-1] == prev){
            dfs(sr, sc-1, prev, color, image);
        }
        if(sc+1 < image[0].size() && image[sr][sc+1] == prev){
            dfs(sr, sc+1, prev, color, image);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int prev = image[sr][sc];
        if(prev == color) return image;
        dfs(sr, sc, prev, color, image);
        return image;
    }
};