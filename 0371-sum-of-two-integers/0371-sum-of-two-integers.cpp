class Solution {
public:
    int getSum(int a, int b) {
        int ans = a ^ b;
        int carry = (a & b) << 1;
        while(carry != 0){
            int sum = ans ^ carry;
            int temp = (ans & carry) << 1;
            ans = sum;
            carry = temp;
        }
        return ans;
    }
};