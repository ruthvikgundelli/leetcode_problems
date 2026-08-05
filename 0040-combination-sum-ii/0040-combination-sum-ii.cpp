class Solution {
public:
    void dfs(vector<int>& candidates, int i, int sum, int target,
             vector<int>& res, vector<vector<int>>& ans, bool prevTaken) {
        if (sum == target) {
            ans.push_back(res);
            return;
        }
        if (i >= candidates.size() || sum > target) {
            return;
        }
        if (i == 0 || candidates[i] != candidates[i - 1] || prevTaken) {
            res.push_back(candidates[i]);
            dfs(candidates, i + 1, sum + candidates[i], target, res, ans, true);
            res.pop_back();
        }
        dfs(candidates, i + 1, sum, target, res, ans, false);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> res;
        dfs(candidates, 0, 0, target, res, ans, false);
        return ans;
    }
};