class Solution {
public:
    int divide(int dividend, int divisor) {
        bool sign = (dividend >> 31) ^ (divisor >> 31);
        long n = labs((long)dividend);
        long d = labs((long)divisor);
        if(n == d) return sign ? -1 : 1;
        long q = 0;
        while(n >= d){
            int k = 0;
            while((d << (k+1)) <= n){
                k++;
            }
            q += 1L<<k;
            n = n - (d << k);
        }
        if (sign) q = -q;
        if(q >= (1L<<31) && !sign) return INT_MAX;
        if(q >= (1L<<31) && sign) return INT_MIN;
        return q;
    }
};