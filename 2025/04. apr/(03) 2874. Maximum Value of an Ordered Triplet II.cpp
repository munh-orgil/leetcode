#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    long long maximumTripletValue(vector<int>& a) {
        using ll = long long;
        int n = a.size();
        ll x = a[0];
        ll y = -1e9;
        ll ret = 0;
        for (int i = 1; i < n; i++) {
            ret = max(ret, y * a[i]);
            y = max(y, x - a[i]);
            x = max(x, ll(a[i]));
        }
        return ret;
    }
};