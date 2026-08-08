class Solution {
public:
    int jump(vector<int>& nums) {
        int ans = 0;
        int maxIdx = 0;
        int prev = 0;
        for(int i = 0; i < nums.size()-1; i++){
            maxIdx = max(maxIdx, i + nums[i]);
            if (i == prev) {
                ans++;
                prev = maxIdx;
            }
        }
        return ans;
    }
};