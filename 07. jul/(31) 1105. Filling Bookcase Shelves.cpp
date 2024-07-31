#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        vector<int> pre(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pre[i + 1] = pre[i] + books[i][0];
        }
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (n, { int(1e9), 0 }));
        dp[0][0] = { 0, books[0][1] };
        int mn;
        for (int i = 1; i < n; i++) {
            mn = 1e9;
            for (int j = 0; j < i; j++) {
                mn = min(mn, dp[i - 1][j][0] + dp[i - 1][j][1]);
                if (dp[i - 1][j][0] != 1e9 && pre[i + 1] - pre[j] <= shelfWidth) {
                    dp[i][j][0] = dp[i - 1][j][0];
                    dp[i][j][1] = max(dp[i - 1][j][1], books[i][1]);
                }
            }
            dp[i][i][0] = mn;
            dp[i][i][1] = books[i][1];
        }
        int ret = 1e9;
        for (int i = 0; i < n; i++) {
            ret = min(ret, dp[n - 1][i][0] + dp[n - 1][i][1]);
        }
        return ret;
    }
};