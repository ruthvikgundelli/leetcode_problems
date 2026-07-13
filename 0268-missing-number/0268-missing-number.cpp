class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // int sum = 0;
        // for(auto x : nums){
        //     sum += x;
        // }
        // long long total = (nums.size())*(nums.size()+1)/2;
        // int ans = total - sum;
        // return ans;
        int n = nums.size();
        int XOR = 0;
        while(n){
            XOR = XOR^n;
            n--;
        }
        for(auto x : nums){
            XOR = XOR^x;
        }
        return XOR;
    }
};