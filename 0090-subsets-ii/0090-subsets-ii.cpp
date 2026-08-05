class Solution {
public:
    void dfs(vector<int>& nums, int i, set<vector<int>>& check, vector<int>& res, vector<vector<int>>& ans){
        if(i >= nums.size()){
            if(check.find(res) == check.end()){
                ans.push_back(res);
                check.insert(res);
            }
            return;
        }
        res.push_back(nums[i]);
        dfs(nums,i+1,check,res,ans);
        res.pop_back();
        dfs(nums,i+1,check,res,ans);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> res;
        set<vector<int>> check;
        sort(nums.begin(), nums.end());
        dfs(nums, 0, check, res, ans);
        return ans;
    }
};