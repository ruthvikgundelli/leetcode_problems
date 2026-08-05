class Solution {
public:
    // vector<vector<int>> subsets(vector<int>& nums) { // Bit Manipulation
    //     int n = 1 << nums.size();
    //     vector<vector<int>> ans;
    //     for(int i=0;i<n;i++){
    //         vector<int> temp;
    //         int take = i, idx = 0;
    //         while(take != 0){
    //             if(take&1) temp.push_back(nums[idx]);
    //             idx++;
    //             take >>= 1;
    //         }
    //         ans.push_back(temp);
    //     }
    //     return ans;
    // }
    
    void dfs(vector<int>& nums, int i, vector<int>& res, vector<vector<int>>& ans){
        if(i >= nums.size()){
            ans.push_back(res);
            return;
        }
        res.push_back(nums[i]);
        dfs(nums,i+1,res,ans);
        res.pop_back();
        dfs(nums,i+1,res,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> res;
        dfs(nums,0,res,ans);
        return ans;
    }

};