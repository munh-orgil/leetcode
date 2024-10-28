#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int longestSquareStreak(vector<int>& a) {
        int n = a.size();
        sort(a.begin(), a.end());
        int ret = 1;
        vector<int> dp(a.back() + 1, 0);
        for (int i = 0; i < n; i++) {
            dp[a[i]] = 1;
        }
        for (int i = 1; i < n; i++) {
            int x = sqrt(a[i]);
            if (x * x != a[i]) continue;
            dp[a[i]] = max(dp[a[i]], dp[x] + 1);
            ret = max(ret, dp[a[i]]);
        }
        return (ret == 1 ? -1 : ret);
    }
};