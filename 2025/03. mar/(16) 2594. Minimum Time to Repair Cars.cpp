#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    using ll = long long;
    ll repairCars(vector<int>& a, ll c) {
        ll l = 0;
        ll r = ll(*min_element(a.begin(), a.end())) * c * c;
        ll m, ret = r, cnt;
        while (l <= r) {
            m = (l + r) / 2;
            cnt = 0;
            for (ll i : a) {
                cnt += sqrt(ll(m / i));
            }
            if (cnt >= c) {
                ret = min(ret, m);
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return ret;
    }
};