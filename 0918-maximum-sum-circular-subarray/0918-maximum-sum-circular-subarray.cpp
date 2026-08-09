class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int mini = INT_MAX;
        int maxi = INT_MIN;
        int total = 0;
        int maxCurr = 0;
        int minCurr = 0;
        for(auto x : nums){
            total += x;
            maxCurr += x;
            maxi = max(maxi, maxCurr);
            if(maxCurr < 0) maxCurr = 0;
            minCurr += x;
            mini = min(mini, minCurr);
            if(minCurr > 0) minCurr = 0;
        }
        if(maxi < 0) return maxi;
        return max(maxi, total - mini);
    }
};