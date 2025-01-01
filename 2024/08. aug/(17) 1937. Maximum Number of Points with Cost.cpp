#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
#define ll long long
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    long long maxPoints(vector<vector<int>>& a) {
        ll n = a.size();
        ll m = a[0].size();
        vector dp(n, vector<ll> (m, 0));
        for (ll i = 0; i < m; i++) {
            dp[0][i] = a[0][i];
        }
        ll mx;
        for (ll i = 1; i < n; i++) {
            mx = 0;
            for (ll j = 0; j < m; j++) {
                mx = max(mx, j + dp[i - 1][j]);
                dp[i][j] = max(dp[i][j], mx - j + a[i][j]);
            }
            mx = 0;
            for (ll j = m - 1; j >= 0; j--) {
                mx = max(mx, m - j - 1 + dp[i - 1][j]);
                dp[i][j] = max(dp[i][j], mx - m + j + 1 + a[i][j]);
            }
        }
        return *max_element(dp[n - 1].begin(), dp[n - 1].end());
    }
};