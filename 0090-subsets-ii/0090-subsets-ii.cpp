class Solution {
public:
    void dfs(vector<int>& nums, int idx, vector<int>& res, vector<vector<int>>& ans){
        ans.push_back(res);
        for(int i = idx; i < nums.size(); i++){
            if (i > idx && nums[i] == nums[i-1]) continue;
            res.push_back(nums[i]);
            dfs(nums,i+1,res,ans);
            res.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> ans;
        vector<int> res;
        dfs(nums, 0, res, ans);
        return ans;
    }
};