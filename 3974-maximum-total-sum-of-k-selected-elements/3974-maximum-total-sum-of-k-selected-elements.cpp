class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        sort(nums.begin(),nums.end(), greater<int>());
        long long sum = 0;
        int idx = 0;
        while(k-- && idx < nums.size()){
            if(mul > 1) sum += 1LL * mul * nums[idx];
            else sum += nums[idx];
            idx++;
            mul--;
        }
        return sum;
    }
};