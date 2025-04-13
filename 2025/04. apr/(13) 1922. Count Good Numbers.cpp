#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        cin.tie(0);
        cout.tie(0);
        ios_base::sync_with_stdio(0);
    }
    using ll = long long;
    int countGoodNumbers(ll n) {
        const int mod = 1e9 + 7;
        function<ll(ll, ll)> f;
        f = [&](ll a, ll x) -> ll {
            if (!x) return 1;
            ll sub = f(a, x / 2);
            ll ret = (sub * sub) % mod;
            if (x % 2) ret = (ret * a) % mod;
            return ret;
            };

        ll ret = (f(4, n / 2) * f(5, (n + 1) / 2)) % mod;
        return ret;
    }
};