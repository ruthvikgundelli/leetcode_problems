class Solution {
public:
    void dfs(TreeNode* node, int row, int col, vector<tuple<int, int, int>>& nodes) {
        if(node == nullptr) return;
        nodes.emplace_back(col,row,node->val);
        dfs(node->left,row+1,col-1,nodes);
        dfs(node->right,row+1,col+1,nodes);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<tuple<int,int,int>> nodes;
        dfs(root, 0, 0, nodes);
        sort(nodes.begin(),nodes.end());
        vector<vector<int>> ans;
        int prev = INT_MIN;
        for(auto [col, row, val] : nodes){
            if(col != prev){
                ans.push_back({});
                prev = col;
            }
            ans.back().push_back(val);
        }
        return ans;
    }
};