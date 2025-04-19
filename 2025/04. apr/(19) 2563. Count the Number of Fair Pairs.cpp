#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    using ll = long long;
    ll countFairPairs(vector<int>& a, int lower, int upper) {
        int n = a.size();
        sort(a.begin(), a.end());
        ll ret = 0;
        for (int i = 0; i < n; i++) {
            ll l = lower_bound(a.begin(), a.end(), lower - a[i]) - a.begin();
            ll r = upper_bound(a.begin(), a.end(), upper - a[i]) - a.begin();
            while (r >= n || (r >= 0 && a[r] + a[i] > upper)) {
                r--;
            }
            if (l <= r) {
                ret += (r - l) + !(l <= i && i <= r);
            }
        }
        return ret / 2;
    }
};