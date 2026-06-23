class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> sum;
        for(int i=0;i<nums.size();i++){
            int y = target - nums[i];
            if(sum.count(y)){
                return {sum[y],i};
            }
            sum[nums[i]] = i;
        }
        return {-1,-1};
    }
};