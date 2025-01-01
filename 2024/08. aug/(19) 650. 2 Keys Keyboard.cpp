#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int minSteps(int n) {
        vector<int> dp(n + 1, 1e9);
        dp[1] = 0;
        for (int i = 2; i <= n; i++) {
            for (int j = 2; j <= n; j++) {
                if (i % j == 0) {
                    dp[i] = min(dp[i], dp[i / j] + j);
                }
            }
        }
        return dp[n];
    }
};