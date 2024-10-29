#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int maxMoves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector dp(n, vector<int> (m, 0));
        for (int i = 0; i < n; i++) {
            dp[i][0] = 1;
        }
        int ret = 1;
        for (int j = 1; j < m; j++) {
            for (int i = 0; i < n; i++) {
                if (grid[i][j] > grid[i][j - 1] && dp[i][j - 1]) dp[i][j] = dp[i][j - 1] + 1;
                if (i && grid[i][j] > grid[i - 1][j - 1] && dp[i - 1][j - 1]) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
                if (i < n - 1 && grid[i][j] > grid[i + 1][j - 1] && dp[i + 1][j - 1]) dp[i][j] = max(dp[i][j], dp[i + 1][j - 1] + 1);
                ret = max(ret, dp[i][j]);
            }
        }
        return ret - 1;
    }
};