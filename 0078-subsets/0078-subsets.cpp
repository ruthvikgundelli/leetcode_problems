class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = 1 << nums.size();
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            if(i == 0) {
                ans.push_back({});
            }
            else{
                vector<int> temp;
                int take = i, idx = 0;
                while(take != 0){
                    if(take&1) temp.push_back(nums[idx]);
                    idx++;
                    take >>= 1;
                }
                ans.push_back(temp);
            }
        }
        return ans;
    }
};