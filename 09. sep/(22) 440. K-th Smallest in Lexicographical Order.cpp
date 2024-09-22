#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
#define ll long long
    void rec(ll n, ll k, bool hasZero, vector<ll>& res) {
        if (!n || !k) return;
        ll each = 0;
        ll p = 1;
        while (n >= p * 10) {
            p *= 10;
            each = each * 10 + 1;
        }
        vector<ll> a(10, each);
        a[0] *= hasZero;
        n -= each * (9 + hasZero);
        ll idx = 1 - hasZero, d;
        while (n > 0) {
            d = min((ll)(n), p);
            a[idx] += d;
            n -= d;
            idx++;
        }
        idx = 9;
        while (n < 0) {
            d = min(a[idx], abs(n));
            a[idx] -= d;
            n += d;
            idx--;
        }
        for (ll i = 0; i < 10; i++) {
            if (a[i] < k) {
                k -= a[i];
            } else {
                res.push_back(i);
                k--;
                rec(a[i] - 1, k, 1, res);
                break;
            }
        }
    }

    ll findKthNumber(ll n, ll k) {
        vector<ll> a;
        rec(n, k, 0, a);
        ll ret = 0;
        for (ll x : a) {
            ret = ret * 10 + x;
        }
        return ret;
    }
};