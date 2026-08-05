class Solution {
public:
    typedef long long ll;
    int myAtoi(string s) {
        ll size = s.size();
        ll i = 0;
        ll ans = 0;
        bool positive = true;
        while (i < size && s[i] == ' ') i++;
        if (i < size && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') positive = false;
            i++;
        }
        while(i < size){
            if(s[i] < '0' || s[i] > '9') break;
            ans = ans * 10 + (s[i] - '0');

            if (positive && ans > INT_MAX) return INT_MAX;
            if (!positive && -ans < INT_MIN) return INT_MIN;
            i++;
        }
        return positive ? ans : -ans;
    }
};