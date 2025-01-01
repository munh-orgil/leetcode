#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int minFallingPathSum(const vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dp(n, vector<int> (n, 1e9));
        for (int i = 0; i < n; i++) {
            dp[0][i] = grid[0][i];
        }
        for (int i = 1; i < n; i++) {
            int mn1 = 1e9, mn2 = 1e9;
            int idx1, idx2;
            for (int j = 0; j < n; j++) {
                if (dp[i - 1][j] <= mn1) {
                    idx2 = idx1;
                    idx1 = j;
                    mn2 = mn1;
                    mn1 = dp[i - 1][j];
                }
                else {
                    if (dp[i - 1][j] < mn2) {
                        idx2 = j;
                        mn2 = dp[i - 1][j];
                    }
                }
            }
            for (int j = 0; j < n; j++) {
                if (j != idx1) {
                    dp[i][j] = mn1 + grid[i][j];
                }
                else {
                    dp[i][j] = mn2 + grid[i][j];
                }
            }
        }
        int ret = 1e9;
        for (int i = 0; i < n; i++) {
            ret = min(ret, dp[n - 1][i]);
        }
        return ret;
    }
};