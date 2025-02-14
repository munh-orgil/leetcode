#include<bits/stdc++.h>

using namespace std;

class ProductOfNumbers {
public:
    using ll = long long;
    const ll mod = 1e9 + 7;
    ll total;
    vector<ll> pre;
    int idx = -1, m = 1;
    ll mult(ll x, ll y) {
        x %= mod;
        y %= mod;
        return (x * y) % mod;
    }
    ll pw(ll a, ll n) {
        if (n == 0) return 1;
        ll sub = pw(a, n / 2);
        ll ret = mult(sub, sub);
        if (n % 2) ret = mult(ret, a);
        return ret;
    }
    ProductOfNumbers() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        total = 1;
        pre.assign(1, 1);
    }
    void add(int num) {
        if (!num) {
            idx = pre.size();
        } else {
            m = mult(m, pw(num, mod - 2));
            total = mult(total, num);
        }
        pre.push_back(m);
    }
    int getProduct(int k) {
        int suf = pre.size() - k;
        if (suf < idx) {
            return 0;
        }
        return mult(total, pre[suf]);
    }
};