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
    ll minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        int n = robot.size();
        int m = factory.size();
        vector dp(n + 1, vector(m + 1, vector<ll> (n + 1, 1e15)));
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                dp[0][i][j] = 0;
            }
        }
        ll sum, mn, idx;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ll mn = dp[i + 1][j][0];
                dp[i + 1][j + 1][factory[j][1]] = mn;
                for (int k = factory[j][1] - 1; k >= 0; k--) {
                    dp[i + 1][j + 1][k] = min(mn, dp[i][j + 1][k + 1] + abs(robot[i] - factory[j][0]));
                }
            }
        }
        return dp[n][m][0];
    }
};