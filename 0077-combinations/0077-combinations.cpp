class Solution {
public:
    void dfs(int n, int k, int i, vector<int>& res, vector<vector<int>>& ans){
        if(res.size() == k){
            ans.push_back(res);
            return;
        }
        if(i > n || res.size() + (n - i + 1) < k) return;
        res.push_back(i);
        dfs(n, k, i+1, res, ans);
        res.pop_back();
        dfs(n, k, i+1, res, ans);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> res;
        dfs(n, k, 1, res, ans);
        return ans;
    }
};