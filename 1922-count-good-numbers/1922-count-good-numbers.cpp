class Solution {
public:
    typedef long long ll;
    const int MOD = 1e9 + 7;
    ll modPow(int x, ll n){
        if(n == 0) return 1;
        ll half = modPow(x,n/2);
        ll ans = (half * half) % MOD;
        if(n&1) ans = (ans * x) % MOD;
        return ans;
    }
    int countGoodNumbers(ll n) {
        ll ans;
        if(n&1) ans = (1LL * modPow(5,(n/2 + 1)) * modPow(4,n/2)) % MOD;
        else ans = (1LL * modPow(5,n/2) * modPow(4,n/2)) % MOD;
        return ans;
    }
};