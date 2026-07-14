class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = 1 << nums.size();
        int ans = 0;
        for(int i=1;i<n;i++){
            int take = i, idx = 0;
            int XOR = 0;
            while(take != 0){
                if(take&1) XOR ^= nums[idx];
                idx++;
                take >>= 1;
            }
            ans += XOR;
        }
        return ans;
    }
};