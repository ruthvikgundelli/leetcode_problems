class Solution {
public:
    void dfs(vector<int>& nums, vector<bool>& used, vector<int>& res, vector<vector<int>>& ans){
        if (res.size() == nums.size()) {
            ans.push_back(res);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            if(used[i]) continue;
            if(i > 0 && nums[i] == nums[i-1] && !used[i-1]) continue;
            res.push_back(nums[i]);
            used[i] = true;
            dfs(nums,used,res,ans);
            used[i] = false;
            res.pop_back();
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> res;
        vector<bool> used(nums.size(), false);
        dfs(nums,used,res,ans);
        return ans;
    }
};