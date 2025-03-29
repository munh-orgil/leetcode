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
    const int mod = 1e9 + 7;
    int count(int x) {
        int ret = 0;
        bool ok;
        int r = sqrt(x);
        for (int i = 2; i <= r; i++) {
            ok = 0;
            while (x % i == 0) {
                ok = 1;
                x /= i;
            }
            ret += ok;
        }
        if (x > 1) ret++;
        return ret;
    }
    int add(int x, int y) { return (ll(x % mod) + ll(y % mod)) % mod; }
    int mult(int x, int y) { return (ll(x % mod) * ll(y % mod)) % mod; }
    int pow(int x, int n) {
        if (!n) return 1;
        int y = pow(x, n / 2);
        int ret = mult(y, y);
        if (n % 2) ret = mult(ret, x);
        return ret;
    }
    int maximumScore(vector<int>& a, int k) {
        int n = a.size();
        vector<int> c(n);
        for (int i = 0; i < n; i++) {
            c[i] = count(a[i]);
        }
        using pii = pair<ll, ll>;
        vector<pii> p(n), b(n);
        stack<pii> l, r;
        for (int i = 0; i < n; i++) {
            while (l.size() && l.top().first < c[i]) {
                l.pop();
            }
            int li = -1;
            if (l.size()) {
                li = l.top().second;
            }
            l.push({ c[i], i });
            p[i].first = i - li;
        }
        for (int i = n - 1; i >= 0; i--) {
            while (r.size() && r.top().first <= c[i]) {
                r.pop();
            }
            int ri = n;
            if (r.size()) {
                ri = r.top().second;
            }
            r.push({ c[i], i });
            p[i].second = ri - i;
        }
        for (int i = 0; i < n; i++) {
            b[i] = { a[i], ll(p[i].first) * ll(p[i].second) };
        }
        sort(b.rbegin(), b.rend());
        int ret = 1;
        int idx = 0;
        while (k) {
            ll mn = min(ll(k), b[idx].second);
            k -= mn;
            b[idx].second -= mn;
            ret = mult(ret, pow(b[idx].first, mn));
            if (!b[idx].second) idx++;
        }
        return ret;
    }
};