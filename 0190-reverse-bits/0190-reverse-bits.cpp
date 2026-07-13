class Solution {
public:
    int reverseBits(int n) {
        int bit, ans=0;
        int bits = 32;
        while(bits--){
            bit = n & 1;
            ans = ans << 1;
            ans = ans | bit;
            n = n >> 1;
        }
        return ans;
    }
};