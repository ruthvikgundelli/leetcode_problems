class Solution {
public:
    void dfs(vector<int>& candidates, int i, int sum, int target, vector<int>& res, vector<vector<int>>& ans){
        if(sum == target){
            ans.push_back(res);
            return;
        }
        if(i >= candidates.size() || sum > target){
            return;
        }
        res.push_back(candidates[i]);
        dfs(candidates,i,sum+candidates[i],target,res,ans);
        res.pop_back();
        dfs(candidates,i+1,sum,target,res,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> res;
        dfs(candidates,0,0,target,res,ans);
        return ans;
    }
};