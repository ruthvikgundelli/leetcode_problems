class Solution {
public:
    void dfs(vector<int>& nums, int i, int k, int n, int sum, vector<int>& res, vector<vector<int>>& ans){
        if(sum == n && res.size() == k){
            ans.push_back(res);
            return;
        }
        if (i == nums.size() || sum > n || res.size() >= k) {
            return;
        }
        if(res.size() + (nums.size()-i) < k) return;
        res.push_back(nums[i]);
        dfs(nums, i+1, k, n, sum + nums[i], res, ans);
        res.pop_back();
        dfs(nums, i+1, k, n, sum, res, ans);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> res;
        vector<int> nums(9);
        iota(nums.begin(),nums.end(),1);
        dfs(nums,0,k,n,0,res,ans);
        return ans;
    }
};